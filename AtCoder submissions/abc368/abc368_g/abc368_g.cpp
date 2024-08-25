#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    fenwick_tree<ll> d(n);
    rep(i,n) d.add(i,a[i]);
    set<int> st;
    rep(i,n) if(b[i]>1) st.insert(i);
    st.insert(n);

    int q;
    cin >> q;
    rep(qi,q){
        int t;
        cin >> t;
        if(t==1){
            int i;
            ll x;
            cin >> i >> x;
            i--;
            d.add(i, x-a[i]);
            a[i] = x;
        }
        if(t==2){
            int i;
            ll x;
            cin >> i >> x;
            i--;
            b[i] = x;
            if(b[i]>1) st.insert(i);
            else st.erase(i);
        }
        if(t==3){
            int l, r;
            cin >> l >> r;
            l--;
            
            ll v = 0;
            while(l<r){
                int i = *st.lower_bound(l);
                i = min(i,r);
                v += d.sum(l,i);
                if(i==r) break;
                v = max(v+a[i],v*b[i]);
                l = i+1;
            }
            cout << v << endl;
        }
    }
}
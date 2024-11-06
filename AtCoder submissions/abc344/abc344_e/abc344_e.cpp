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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int st=a[0], gl=a[n-1];
    map<ll,ll> f, b;
    rep(i,n){
        if(i!=n-1) f[a[i]] = a[i+1];
        if(i!=0) b[a[i]] = a[i-1];
    }

    int q;
    cin >> q;
    rep(qi,q){
        int t;
        cin >> t;
        if(t==1){
            ll x, y;
            cin >> x >> y;
            if(x==gl){
                f[x] = y;
                b[y] = x;
                gl = y;
            }
            else{
                ll nex = f[x];
                f[x] = y;
                f[y] = nex;
                b[nex] = y;
                b[y] = x;
            }
        }
        if(t==2){
            ll x;
            cin >> x;
            if(x==st){
                st = f[x];
            }
            if(x==gl){
                gl = b[x];
            }
            else {
                ll nex = f[x];
                ll pre = b[x];
                f[pre] = nex;
                b[nex] = pre;
            }
        }
    }

    while(true){
        cout << st << " ";
        if(st==gl) break;
        st = f[st];
    }
    cout << endl;
}
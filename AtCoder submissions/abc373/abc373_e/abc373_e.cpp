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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    if(n==m){
        rep(i,n) cout << 0 << " ";
        cout << endl;
        return 0;
    }

    vector<ll> a = A;
    sort(a.begin(),a.end());
    vector<ll> s(n+1,0);
    rep(i,n) s[i+1] = s[i] + a[i];
    ll remain = k;
    remain -= s[n];

    map<int,ll> ans;
    rep(i,n){
        auto judge = [&](ll x){
            ll y = a[i] + x;
            int r = upper_bound(a.begin(),a.end(),y+1) - a.begin();
            int l = n - m;
            if(r<l) return false;
            ll need = (y+1)*(r-l) - (s[r] - s[l]);
            if(l<=i && i<r){
                need += a[i];
                need -= a[l-1];
            }
            return need > remain-x;
        };

        ll ac = remain + 1, wa = -1;
        while(ac-wa>1){
            ll wj = (ac+wa)/2;
            if(judge(wj)) ac = wj;
            else wa = wj;
        }

        if(ac==remain+1) ac = -1;
        ans[a[i]] = ac;
    }

    rep(i,n) cout << ans[A[i]] << " ";
    cout << endl; 
}
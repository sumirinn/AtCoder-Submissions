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
    int h, w, m;
    cin >> h >> w >> m;
    ll H=h, W=w;

    vector<bool> h_used(h,false), w_used(w,false);

    vector<int> t(m), a(m), x(m);
    rep(i,m){
        cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }

    const int k = 2e5 + 6;
    vector<ll> col(k,0);
    for(int i=m-1; i>=0; i--){
        if(t[i]==1){
            if(h_used[a[i]]) continue;
            col[x[i]] += w;
            h_used[a[i]] = true;
            h--;
        }
        if(t[i]==2){
            if(w_used[a[i]]) continue;
            col[x[i]] += h;
            w_used[a[i]] = true;
            w--;
        }
    }
    ll sum = 0;
    repp(i,k-1) sum += col[i];
    col[0] = H*W - sum;

    int ans = 0;
    rep(i,k)if(col[i]!=0) ans++;
    cout << ans << endl;
    rep(i,k)if(col[i]!=0) cout << i << " " << col[i] << endl;
}
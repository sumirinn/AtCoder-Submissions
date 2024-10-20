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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int h, w;
    ll k;
    cin >> h >> w >> k;
    int sh, sw;
    cin >> sh >> sw;
    sh--; sw--;
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];

    int hw = h*w;
    using vvl = vector<vector<ll>>;
    vector<vvl> dp(hw,vvl(h,vector<ll>(w,-INF)));
    dp[0][sh][sw] = 0;
    rep(s,hw-1)rep(i,h)rep(j,w)rep(v,4){
        int ni=i+di[v], nj=j+dj[v];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        chmax(dp[s+1][ni][nj],dp[s][i][j]+a[ni][nj]);
    }

    ll ans = 0;
    rep(s,hw)rep(i,h)rep(j,w){
        if(s>k) continue;
        ll now = (ll)(k-s)*a[i][j] + dp[s][i][j];
        chmax(ans,now);
    }
    cout << ans << endl;
}
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
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n,vector<ll>(n,INF));
    vector<vector<ll>> dp(n,vector<ll>(n,INF));
    rep(i,n) dp[i][i] = 0;
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u][v] = w;
        dp[u][v] = dp[v][u] = w;
    }

    rep(k,n)rep(i,n)rep(j,n){
        chmin(dp[i][j], dp[i][k]+dp[k][j]);
    }

    int ans = 0;
    rep(i,n)rep(j,n)if(g[i][j]!=INF){
        bool ok = false;
        rep(k,n){
            if(i==k || j==k) continue;
            if(dp[i][k]+dp[k][j]<=g[i][j]) ok = true;
        }
        if(ok) ans++;
    }

    cout << ans << endl;
}
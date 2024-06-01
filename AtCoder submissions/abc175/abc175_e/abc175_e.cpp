#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
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
//mint::set_mod(m);で定義できる。
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
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
    int r, c, k;
    cin >> r >> c >> k;
    map<pii,ll> mp;
    vector<vector<ll>> w(r,vector<ll>(c,0));
    rep(ki,k){
        int R, C;
        ll v;
        cin >> R >> C >> v;
        R--; C--;
        w[R][C] = v;
    }
    
    int n = 4;
    ll dp[r][c][n];
    rep(i,r)rep(j,c)rep(k,n) dp[i][j][k] = 0;
    rep(i,r)rep(j,c){
        if(i!=0) rep(k,n)chmax(dp[i][j][0],dp[i-1][j][k]);
        if(j!=0) rep(k,n)chmax(dp[i][j][k],dp[i][j-1][k]);
        if(w[i][j]!=0){
            repb(k,n-1) chmax(dp[i][j][k+1],dp[i][j][k]+w[i][j]);
        }
    }

    ll ans = 0;
    rep(k,n) chmax(ans,dp[r-1][c-1][k]);
    cout << ans << endl;
}
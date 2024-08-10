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
using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n;
    cin >> n;
    vector<vector<vector<int>>> a(n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
    rep(i,n)rep(j,n)rep(k,n) cin >> a[i+1][j+1][k+1];

    rep(i,n+1)rep(j,n+1)rep(k,n) a[i][j][k+1] += a[i][j][k];
    rep(i,n+1)rep(j,n)rep(k,n+1) a[i][j+1][k] += a[i][j][k];
    rep(i,n)rep(j,n+1)rep(k,n+1) a[i+1][j][k] += a[i][j][k];

    int q;
    cin >> q;
    vector<int> ans;
    rep(qi,q){
        int i1, i2, j1, j2, k1, k2;
        cin >> i1 >> i2 >> j1 >> j2 >> k1 >> k2;
        i1--; j1--; k1--;
        ans.pb(a[i2][j2][k2] -a[i1][j2][k2]-a[i2][j1][k2]-a[i2][j2][k1] +a[i1][j1][k2]+a[i2][j1][k1]+a[i1][j2][k1] - a[i1][j1][k1]);
    }

    for(int answer : ans) cout << answer << endl;
}
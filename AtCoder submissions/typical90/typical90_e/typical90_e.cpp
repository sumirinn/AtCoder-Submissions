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
using P = pair<int, pii>;
using C = complex<double>;
void chmax(int& x, int y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};



int main(){
    ll n;
    int b, k;
    cin >> n >> b >> k;
    vector<int> c(k);
    rep(i,k) cin >> c[i];

    const int m = 62;
    vector<int> ten(m,10);
    repp(i,m-1) ten[i] = (ten[i-1]*ten[i-1]) % b;

    vector<vector<mint>> dp(m,vector<mint>(b,0));
    rep(i,k) dp[0][c[i]%b] += 1;
    repp(i,m-1){
        rep(p,b)rep(q,b){
            dp[i][(p*ten[i-1] + q)%b] += dp[i-1][p]*dp[i-1][q];
        }
    }

    vector<mint> ans(b,0);
    ans[0] = 1;
    rep(i,m){
        if(n&(ll)1<<i){
            vector<mint> pre(b,0);
            swap(pre,ans);
            rep(p,b)rep(q,b){
                ans[(p*ten[i] + q)%b] += pre[p]*dp[i][q];
            }
        }
    }
    cout << ans[0].val() << endl;
}
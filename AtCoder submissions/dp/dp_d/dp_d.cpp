#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    ll dp[n+5][W+5];
    rep(i, n+1)rep(j, W+1) dp[i][j] = 0;
    rep(i, n)rep(j, W+1){
        chmax(dp[i+1][j], dp[i][j]);
        if(j+w[i]<=W) chmax(dp[i+1][j+w[i]], dp[i][j] + v[i]);
    }

    ll ans = 0;
    rep(i, W+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
}
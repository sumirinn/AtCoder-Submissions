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
void chmax(int& x, int y) {x = max(x, y);} // change max
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


int dp[209][209];

int main(){
    int d, n;
    cin >> d >> n;
    vector<int> t(d), a(n), b(n), c(n);
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    rep(i, d+1)rep(j, n+1) dp[i][j] = 0;

    rep(i, d){
        rep(j, n){
            if(t[i]<a[j] || b[j]<t[i]){
                dp[i+1][j] = -inf;
                continue;
            }
            if(i==0) continue;
            int C = c[j];
            rep(s, n) chmax(dp[i+1][j], dp[i][s] + abs(C-c[s]));
        }
    }

    int ans = 0;
    rep(i, n) chmax(ans, dp[d][i]);
    cout << ans << endl;
}
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
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

ll dp[105][105][100];

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n+1)rep(j, k+1)rep(r, d) dp[i][j][r] = -1;
    dp[0][0][0] = 0;

    rep(i, n){
        int ni = i + 1;
        rep(j, k+1)rep(r, d){
            if(dp[i][j][r]==-1) continue;
            ll now = dp[i][j][r];
            {
                int nj = j + 1, nr = (r+a[i])%d;
                chmax(dp[ni][nj][nr], now + a[i]);
            }
            {
                int nj = j, nr = r;
                chmax(dp[ni][nj][nr], now);
            }
        }
    }

    cout << dp[n][k][0] << endl;
}






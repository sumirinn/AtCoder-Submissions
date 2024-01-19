#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

void chmax(ll& x, ll y) {x = max(x, y);}

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    repp(i, n) cin >> x[i] >> y[i];

    const ll inf = 1e18;
    vector<vector<ll>> dp(n+1, vector<ll>(2, -inf));
    dp[0][0] = 0;
    repp(i, n){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        if(x[i]==0){
            chmax(dp[i+1][0], dp[i][0] + y[i]);
            chmax(dp[i+1][0], dp[i][1] + y[i]);
        }
        if(x[i]==1){
            chmax(dp[i+1][1], dp[i][0] + y[i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}
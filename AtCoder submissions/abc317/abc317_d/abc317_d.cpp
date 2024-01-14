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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
void chmin(ll& x, ll y) { x = min(x, y);};
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    int w = 0;

    vector<P> data;
    repp(i, n){
        int x, y, z;
        cin >> x >> y >> z;
        int a = max(0, (y-x+1)/2);
        w += z;
        data.emplace_back(a, z*2);
    }

    const ll inf = 1e18;
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, inf));
    dp[0][0] = 0;

    repp(i, n){
        int a = data[i].first;
        int z = data[i].second;
        repp(j, w+1){
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(w, j+z)], dp[i][j]+a);
        }
    }

    cout << dp[n][w] << endl;
}
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
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

int main(){
    ll x, y, z;
    string s;
    cin>> x >> y >> z >> s;

    ll dp[300009][2];
    rep(i, s.size())repp(j, 2) dp[i][j] = 0;
    dp[0][0] = 0;
    dp[0][1] = z;
    rep(i, s.size()){
        if(s[i-1]=='a'){
            dp[i][0] = min(dp[i-1][0] + x, dp[i-1][1] + z + x);
            dp[i][1] = min(dp[i-1][1] + y, dp[i-1][0] + z + y);
        }
        if(s[i-1]=='A'){
            dp[i][0] = min(dp[i-1][0] + y, dp[i-1][1] + z + y);
            dp[i][1] = min(dp[i-1][0] + z + x, dp[i-1][1] + x);
        }

    }
    cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;
}
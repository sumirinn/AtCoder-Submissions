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
using P = pair<ll, ll>;
//97~122(a~z)

using mint = modint998244353;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    dp[0][0] = 1;
    repp(i, n){
        repp(j, n){
            if(s[i]!=')') dp[i+1][j+1] += dp[i][j];
            if(s[i]!='(' && j>0) dp[i+1][j-1] += dp[i][j];
        }
    }
    cout << dp[n][0].val() << endl;

}
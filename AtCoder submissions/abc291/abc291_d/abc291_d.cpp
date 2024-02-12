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
//97~122(a~z),65~90(A~Z)

int main(){
    int n; cin >> n;
    ll a[200009], b[200009];
    repp(i, n) cin >> a[i] >> b[i];

    mint dp[200009][5];
    repp(i, n){
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i= 2; i<=n; i++){
        if(a[i-1]!=a[i]) dp[i][0] += dp[i-1][0];
        if(b[i-1]!=a[i]) dp[i][0] += dp[i-1][1];
        if(a[i-1]!=b[i]) dp[i][1] += dp[i-1][0];
        if(b[i-1]!=b[i]) dp[i][1] += dp[i-1][1];
    }

    mint ans = dp[n][0] + dp[n][1];
    cout << ans.val() << endl;
}
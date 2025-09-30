#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll INF = 1e18;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = modint1000000007;

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    vl a(n), b(n);
    rep(i,0,n) cin >> a[i] >> b[i];
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (n+1, vector<ll> (x+1, 1e9)));
    dp[0][0][0] = 0;
    rep(i,0,n) rep(j,0,n) rep(k,0,x+1) {
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        if (k+a[i] > x) continue;
        dp[i+1][j+1][k+a[i]] = min(dp[i+1][j+1][k+a[i]], dp[i][j][k] + b[i]);
    }

    for(ll i=n; i>=0; i--) {
        rep(k,0,x+1)
            if (dp[n][i][k] <= y) {
                if(i<n) i++;
                cout << i << endl;
                return 0;
        }
    }
}
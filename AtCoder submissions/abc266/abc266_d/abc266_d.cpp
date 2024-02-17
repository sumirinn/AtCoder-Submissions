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
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    cin >> n;
    vector<int> t(n), x(n), a(n);
    rep(i, n) cin >> t[i] >> x[i] >> a[i];

    vector<vector<ll>> dp(t[n-1]+1, vector<ll>(5, -1));
    dp[0][0] = 0;

    int k = 0;
    rep(i, t[n-1]){
        if(k<n && t[k]==i+1){
            rep(j, 5){
                if(j==x[k]){
                    if(j-1>=0 && dp[i][j-1]!=-1) chmax(dp[i+1][j], dp[i][j-1] + a[k]);
                    if(dp[i][j]!=-1)chmax(dp[i+1][j], dp[i][j] + a[k]);
                    if(j+1<=4 && dp[i][j+1]!=-1) chmax(dp[i+1][j], dp[i][j+1] + a[k]);
                }else{
                    if(j-1>=0 && dp[i][j-1]!=-1) chmax(dp[i+1][j], dp[i][j-1]);
                    if(dp[i][j]!=-1)chmax(dp[i+1][j], dp[i][j]);
                    if(j+1<=4 && dp[i][j+1]!=-1) chmax(dp[i+1][j], dp[i][j+1]);
                }
            }
            k++;
        }else{
            rep(j, 5){
                if(j-1>=0 && dp[i][j-1]!=-1) chmax(dp[i+1][j], dp[i][j-1]);
                if(dp[i][j]!=-1)chmax(dp[i+1][j], dp[i][j]);
                if(j+1<=4 && dp[i][j+1]!=-1) chmax(dp[i+1][j], dp[i][j+1]);
            }
        }

    }
    
    ll ans = 0;
    rep(i, 5) ans = max(ans, dp[t[n-1]][i]);
    cout << ans << endl;
}
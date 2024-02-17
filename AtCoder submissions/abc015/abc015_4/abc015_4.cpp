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
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int w, n, k;
    cin >> w >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int dp[n+10][k+10][w+10];
    rep(i, n+1)rep(j, k+1)rep(l, w+1) dp[i][j][l] = 0;

    rep(i, n){
        rep(j, k+1){
            rep(l, w+1){  
                chmax(dp[i+1][j][l], dp[i][j][l]);//not choose
                if(l+a[i]<=w) chmax(dp[i+1][j+1][l+a[i]], dp[i][j][l] + b[i]);//choose
            }
        }
    }

    int ans = 0;
    repp(j, k)repp(l, w) chmax(ans, dp[n][j][l]);
    cout << ans << endl;

}
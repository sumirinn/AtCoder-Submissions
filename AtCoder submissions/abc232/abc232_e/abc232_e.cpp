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
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    ll h, w, k;
    cin >> h >> w >> k;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<vector<mint>> dp(2, vector<mint>(2, 0));
    dp[sx==tx][sy==ty] = 1;
    rep(ki, k){
        vector<vector<mint>> p(2, vector<mint>(2, 0));
        swap(dp, p);
        rep(j, 2){
            dp[0][j] += p[0][j]*(h-2);
            dp[1][j] += p[0][j];
            dp[0][j] += p[1][j]*(h-1);
        }
        rep(i, 2){
            dp[i][0] += p[i][0]*(w-2);
            dp[i][1] += p[i][0];
            dp[i][0] += p[i][1]*(w-1);
        }
    }

    cout << dp[1][1].val() << endl;
}
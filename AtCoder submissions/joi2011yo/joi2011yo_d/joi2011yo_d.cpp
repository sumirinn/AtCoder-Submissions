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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

ll dp[109][25];

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    

    rep(i, n+1)rep(j, 21) dp[i][j] = ll(0);
    dp[1][p[0]]++;

    rep(i, n-1){
        if(i==0) continue;
        rep(j, 21){
            if(dp[i][j] && j+p[i]<=20) dp[i+1][j+p[i]] += dp[i][j];
            if(dp[i][j] && j-p[i]>=0) dp[i+1][j-p[i]] += dp[i][j];
        }
    }

    cout << dp[n-1][p[n-1]] << endl; 
}
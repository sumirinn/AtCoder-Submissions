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
void chmin(ll& x, ll y) {x = min(x, y);}
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


int dp[100009];

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
    }

    rep(i, n+1) dp[i] = -1;

    auto rec = [&](auto rec, int v) -> int {
        if(dp[v]!=-1) return dp[v];

        int res = 0;
        for(auto u : to[v]){
            chmax(res, rec(rec, u)+1);
        }

        return dp[v] = res;
    };

    int ans = 0;
    rep(i, n) chmax(ans, rec(rec, i));

    cout << ans << endl;

}
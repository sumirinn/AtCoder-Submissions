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
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m){
        int u, v; 
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    int ans = 0;
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int v) -> void {
        if(ans==1000000) return;
        ans++;
        visited[v] = true;
        for(int u : to[v]){
            if(visited[u]) continue;
            dfs(dfs, u);
        }
        visited[v] = false;
    };
    
    dfs(dfs, 0);
    cout << ans << endl;
}
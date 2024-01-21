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
const int inf = 1001001001;
//97~122(a~z)

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> to(n);
    rep(i, n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    vector<int> ans;
    vector<int> answer;
    vector<bool> visited(n);
    ans.push_back(x);

    auto dfs = [&](auto dfs, int goal, int v) -> void{
        if(goal==v){
            repp(i, ans.size()) cout << ans[i] + 1 << " ";
            cout << endl;
            return;
        }
        visited[v] = true;
        for(int u : to[v]){
            if(visited[u]) continue;
            ans.push_back(u);
            dfs(dfs, goal, u);
            ans.pop_back();
        }
        return;
    };

    dfs(dfs, y, x);
}
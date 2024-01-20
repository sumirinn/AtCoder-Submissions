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
int inf = 1001001001;
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    repp(i, n){
        int c;
        cin >> c;
        repp(j, c){
            int p;
            cin >> p;
            to[i].push_back(p-1);
        }
    }
    
    vector<int> ans;
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int v) -> void {
        visited[v] = true;
        for(int u : to[v]){
            if(visited[u]) continue;
            dfs(dfs, u);
        }
        ans.push_back(v);
    };

    dfs(dfs, 0);
    ans.pop_back();

    for(int i : ans) cout << i + 1 << " ";
    cout << endl;
}
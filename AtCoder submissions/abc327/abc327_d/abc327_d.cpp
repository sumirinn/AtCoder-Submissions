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
//97~122

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<int> a(m), b(m);
    repp(i,m) cin >> a[i], a[i]--;
    repp(i,m) cin >> b[i], b[i]--;
    repp(i,m){
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
    }

    vector<int> color(n, -1);
    auto dfs = [&](auto dfs, int v, int c) -> void {
        if(color[v]!=-1) return;
        color[v] = c;
        for(int u : to[v]) dfs(dfs, u, 1-c);
    };

    repp(i, n) dfs(dfs, i, 0);

    repp(i, m) if(color[a[i]]==color[b[i]]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}

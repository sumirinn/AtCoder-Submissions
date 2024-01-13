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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, P> go;
    int a, b;
    ll X, Y;

    bool visited[200009];
    rep(i, n) visited[i] = false;

    vector<int> g[200009];

    rep(i, m){
        cin >> a >> b >> X >> Y;  
        go[make_pair(a, b)] = make_pair(X, Y);
        go[make_pair(b, a)] = make_pair(-X, -Y);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    P POS[200009];
    POS[0] = P(0, 0);

    auto dfs = [&](auto dfs, int pos) -> void {
        visited[pos] = true;
        repp(i, g[pos].size()){
            int nex = g[pos][i];
            POS[nex] = make_pair(POS[pos].first + go[make_pair(pos, nex)].first, POS[pos].second + go[make_pair(pos, nex)].second);
            if(!(visited[nex])) dfs(dfs, nex);
        }
    };

    dfs(dfs, 1);

    rep(i, n){
        if(visited[i]) cout << POS[i].first << " " << POS[i].second << endl;
        else cout << "undecidable" << endl;
    }
}
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
//97~122(a~z),65~90(A~Z)

struct Edge {
    int a, b; ll w;
    Edge() {}
    Edge(int a, int b, ll w): a(a), b(b), w(w) {}
};

int main(){
    int n, m; ll k; cin >> n >> m >> k;
    vector<Edge> es;
    rep(i, m){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        es.emplace_back(u, v, w);
    }

    ll ans = INF;

    auto dfs = [&](auto dfs, int i, vector<int> is) -> void {
        if(is.size()==n-1){
            dsu uf(n);
            bool ok = true;
            ll now = 0;
            for(int ei : is){
                auto e = es[ei];
                if(uf.same(e.a, e.b)) ok = false;
                uf.merge(e.a, e.b);
                now = (now+e.w) % k;
            }
            if(ok) ans = min(ans, now);
            return;
        }
        if(i==m) return;
        dfs(dfs, i+1, is);
        is.push_back(i);
        dfs(dfs, i+1, is);
    };

    dfs(dfs, 0, {});
    cout << ans << endl;

}
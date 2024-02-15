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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    dsu uf(n);
    vector<P> edges;
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(a[u]==a[v]) uf.merge(u, v);
        edges.emplace_back(u, v);
    }

    vector<vector<int>> to(n);
    for(auto [u, v] : edges){
        u = uf.leader(u);
        v = uf.leader(v);
        if(u==v) continue;
        if(a[u]>a[v]) swap(u, v);
        to[u].push_back(v);
    }

    vector<int> vs;
    rep(i, n) if(uf.leader(i)==i) vs.push_back(i);
    sort(vs.begin(), vs.end(), [&](int u, int v) {
        return a[u] < a[v];
    });

    vector<int> dp(n, -inf);
    dp[uf.leader(0)] = 1;
    for(int v : vs){
        for(int u : to[v]){
            dp[u] = max(dp[u], dp[v]+1);
        }
    }
    int ans = dp[uf.leader(n-1)];
    if(ans<0) ans = 0;
    cout << ans << endl;
}
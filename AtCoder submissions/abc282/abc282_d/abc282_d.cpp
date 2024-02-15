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


    dsu uf(n);
    vector<bool> visited(n);
    bool ok = false;

    auto dfs = [&](auto dfs, int now, int pre) -> void {
        if(visited[now]) return;
        visited[now] = true;
        for(int nex : to[now]){
            if(pre==-1){
                dfs(dfs, nex, now);
            }
            else{
                if(uf.same(now, nex)){
                    ok = true;
                    rep(i, n) visited[i] = true;
                    return;
                }
                uf.merge(pre, nex);
                dfs(dfs, nex, now);
            }
        }
    };
    
    vector<P> v(n);
    rep(i, n) v[i] = P(to[i].size(), i);
    sort(v.begin(), v.end());
    rep(i, n) dfs(dfs, v[i].second, -1);


    if(ok){
        cout << 0 << endl;
        return 0;
    }

    map<int, int> mp;
    rep(i, n) mp[uf.leader(i)] = 0;
    rep(i, n) mp[uf.leader(i)]++;

    ll ans = 0;
    rep(i, n) ans += n-mp[uf.leader(i)] - to[i].size();

    cout << ans / 2 << endl;
}
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
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m; cin >> n >> m;
    dsu uf(n);
    rep(mi, m){
        int u, v; cin >> u >> v; u--; v--;
        uf.merge(u, v);
    }

    vector<bool> cnt(n);
    rep(i, n) cnt[uf.leader(i)] = true;
    int ans = 0;
    rep(i, n) if(cnt[i]) ans++;
    cout << ans << endl;
}
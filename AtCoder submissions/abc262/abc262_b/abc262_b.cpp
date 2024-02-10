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
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> to(n, vector<bool>(n));
    rep(i, m){
        int u, v; cin >> u >> v; u--; v--;
        to[u][v] = true;
        to[v][u] = true;
    }
    int ans = 0;
    repp(i, n)repp(j, n)repp(k, n){
        if(to[i][j] && to[j][k] && to[k][i]) ans++;
    }
    cout << ans / 6 << endl;
}
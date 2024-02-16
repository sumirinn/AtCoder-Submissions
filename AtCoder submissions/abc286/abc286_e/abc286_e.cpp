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
using P = pair<int, ll>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int INF = 1001001001;
//const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<P>> g(n, vector<P>(n, P(INF, 0)));
    rep(i, n) g[i][i] == P(0, 0);
    rep(i, n){
        string s;
        cin >> s;
        rep(j, n){
            if(s[j]=='Y') g[i][j] = P(1, -a[j]);
        }
    }

    auto add = [&](P a, P b) {
        return P(a.first+b.first, a.second+b.second);
    };

    rep(k, n)rep(i, n)rep(j, n) g[i][j] = min(g[i][j], add(g[i][k], g[k][j]));

    int q;
    cin >> q;
    rep(qi, q){
        int s, t;
        cin >> s >> t;
        s--; t--;
        auto [dist, val] = g[s][t];
        if(dist==INF) cout << "Impossible" << endl;
        else cout << dist << " " << a[s] - val << endl;
    }
}
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
//97~122(a~z)
using P = pair<ll, int>;

int main(){
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    ll d[1009][1009];
    rep(i, n)rep(j, n) cin >> d[i][j];

    const ll inf = 1e18;
    auto dijk = [&](int sv, ll b, ll c) {
        vector<ll> dist(n+1);
        rep(i, n) dist[i] = inf;
        dist[sv] = 0;
        bool done[1009];
        rep(i, n) done[i] = false;
        rep(ni, n){
            P best(inf, 0);
            rep(i, n) if(!done[i]) best = min(best, P(dist[i], i));
            int v = best.second;
            done[v] = true;
            rep(i, n) dist[i] = min(dist[i], dist[v]+d[v][i]*b+c);
        }

        return dist;
    };

    auto d1 = dijk(1, a, 0);
    auto d2 = dijk(n, b, c);
    ll ans = 100000000000000000ll;
    rep(i, n) ans = min(ans, d1[i]+d2[i]);
    cout << ans << endl;
}

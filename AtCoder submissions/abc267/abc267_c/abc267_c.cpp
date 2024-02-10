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
    vector<ll> a(n);
    repp(i, n) cin >> a[i];

    ll s = 0, t = 0;
    repp(i, m) s += a[i]*(i+1);
    repp(i, m) t += a[i];

    ll ans = s;
    repp(i, n-m){
        ll ns = s - t + a[i+m]*m;
        ll nt = t - a[i] + a[i+m];
        s = ns; t = nt;
        ans = max(ans, s);
    }
    cout << ans << endl;
}
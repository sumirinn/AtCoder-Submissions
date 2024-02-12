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
    int n, m; 
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m){
        cin >> x[i];
        x[i]--;
    }

    vector<ll> d(n+1);
    auto add = [&](int l, int r, int x) {
        d[l] += x;
        d[r] -= x;
    };
    rep(i, m-1){
        int s = x[i], t = x[i+1];
        if(s>t) swap(s, t);
        int a = t - s, b = n - a;
        add(0, s, a);
        add(s, t, b);
        add(t, n, a);
    }

    rep(i, n) d[i+1] += d[i];

    ll ans = 1e18;
    rep(i, n){
        ans = min(ans, d[i]);
    }
    cout << ans << endl;
}
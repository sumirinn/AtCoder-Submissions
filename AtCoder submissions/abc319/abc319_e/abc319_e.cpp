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
const int dj[] = {0, -1, 0, 1};
const int inf = 1001001001;
//97~122(a~z)

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    n--;
    vector<int> p(n), t(n);
    repp(i, n) cin >> p[i] >> t[i];
    const int m = 840;

    vector<ll> d(m);
    repp(si, m){
        ll now = si + x;
        repp(i, n){
            while(now%p[i]) now++;
            now += t[i];
        }
        now += y;
        d[si] = now - si;
    }

    int q;
    cin >> q;
    repp(qi, q){
        ll now;
        cin >> now;
        now += d[now%m];
        cout << now << '\n';
    }
}
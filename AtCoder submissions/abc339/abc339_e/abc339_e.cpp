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

int op(int a, int b) { return max(a, b);}
int e() { return 0;}

int main(){
    int n, d; cin >> n >> d;
    vector<int> a(n);
    repp(i, n) cin >> a[i];

    const int M = 500005;
    segtree<int, op, e> dp(M);

    repp(i, n){
        int l = a[i]-d, r = a[i]+d+1;
        l = max(l, 0);
        r = min(r, M);
        int now = dp.prod(l, r) + 1;
        dp.set(a[i], now);
    }

    int ans = dp.prod(0, M);
    cout << ans << endl;
}
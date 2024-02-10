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
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    vector<bool> v(101);
    for(int i=l1; i<r1+1; i++) v[i] = true;
    int ans = 0;
    for(int i=l2; i<r2+1; i++) if(v[i]) ans++;
    if(ans) cout << ans-1 << endl;
    else cout << 0 << endl;
}
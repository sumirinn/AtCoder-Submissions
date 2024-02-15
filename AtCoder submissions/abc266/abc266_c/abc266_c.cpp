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
    vector<int> x(4), y(4);
    rep(i, 4) cin >> x[i] >> y[i];

    auto f = [&](int a, int b, int s, int t, int u, int v) -> bool {
        int x1 = a-s, y1 = b-t, x2 = u-s, y2 = v-t;
        if(x1*y2-x2*y1<0) return false;
        return true;
    };

    bool ans = true;
    rep(i, 4){
        if(f(x[i],y[i],x[(i+1)%4],y[(i+1)%4],x[(i+2)%4],y[(i+2)%4])) ans =false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
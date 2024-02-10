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
    int n; cin >> n;
    vector<int> q(n), a(n), b(n); 
    repp(i, n) cin >> q[i];
    repp(i, n) cin >> a[i];
    repp(i, n) cin >> b[i];

    int ans = 0;
    for(int x=0;; x++){
        vector<int> r(n);
        repp(i, n) r[i] = q[i] - a[i]*x;
        bool ok = true;
        repp(i, n) if(r[i]<0) ok = false;
        if(!ok) break;
        int y = inf;
        repp(i, n){
            if(b[i]==0) continue;
            y = min(y, r[i]/b[i]);
        }
        ans = max(ans, x + y);
    }

    cout << ans << endl;
}
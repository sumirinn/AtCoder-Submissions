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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int m;
    string s[10];
    cin >> m;
    repp(i, 3) cin >> s[i];

    int inf = 1001001001;
    int ans = inf;
    int M = 3 * m;
    repp(t0, M)repp(t1, M)repp(t2, M){
        if(t0==t1) continue;
        if(t1==t2) continue;
        if(t2==t0) continue;
        if(s[0][t0%m]!=s[1][t1%m]) continue;
        if(s[1][t1%m]!=s[2][t2%m]) continue;
        ans = min(ans, max({t0, t1, t2}));
    }
    if(ans==inf) ans = -1;
    cout << ans << endl;
}
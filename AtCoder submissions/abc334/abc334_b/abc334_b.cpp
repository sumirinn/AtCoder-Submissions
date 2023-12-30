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

ll a, m, l, r;

ll f(ll x, ll m){
    return x / m;
}

int main(){
    cin >> a >> m >> l >> r;

    l -= a;
    r -= a;

    if(l<0){
        ll x = -l/m + 1;
        l += x * m;
        r += x * m;
    }

    ll ans = f(r, m) - f(l-1, m);
    cout << ans << endl;
    return 0;
}
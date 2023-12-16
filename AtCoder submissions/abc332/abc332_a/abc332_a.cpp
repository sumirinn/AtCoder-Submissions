#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;
ll s, k, p[109], q[109];

int main(){
    cin >> n >> s >> k;
    rep(i, n) cin >> p[i] >> q[i];

    ll ans = 0;
    rep(i, n) ans += p[i] * q[i];

    if(ans<s) ans += k;

    cout << ans << endl;
}
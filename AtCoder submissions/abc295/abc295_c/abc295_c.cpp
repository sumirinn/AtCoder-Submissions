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
    int n;
    ll a[500009];
    cin >> n;
    rep(i, n) cin >> a[i];

    sort(a+1, a+n+1);
    a[n+1] = 1e10;
    int ans = 0;
    rep(i, n) if(a[i]==a[i+1]) ans++, i++;

    cout << ans << endl;
}
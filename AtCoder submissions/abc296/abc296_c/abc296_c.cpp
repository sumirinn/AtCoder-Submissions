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
    ll x, a[200009];
    cin >> n >> x;
    rep(i, n) cin >> a[i];
    a[n+1] = 1e10;

    sort(a+1, a+n+1);
    bool ans = false;
    rep(i ,n){
        int pos = lower_bound(a+1, a+n+2, x+a[i]) - a;
        if(a[pos]-a[i]==x) ans = true;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
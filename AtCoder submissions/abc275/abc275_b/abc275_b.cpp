#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll a, b, c, d, e, f;
ll const m = 998244353;

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    a=a%m, b=b%m, c=c%m, d=d%m, e=e%m, f=f%m;

    ll ab = (a*b)%m;
    ll de = (d*e)%m;
    ll abc = (ab*c)%m;
    ll def = (de*f)%m;
    ll ans = abc - def;
    if(ans<0) ans += m;
    cout << ans << endl;
}
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
    string s;
    cin >> s;
    ll ans = 0;
    ll d = 1;
    for(int i=s.size()-1; i>=0; i--){
        ll a = (ll)s[i] - (ll)'A' + 1;
        ans += a * d;
        d *= 26;
    }

    cout << ans << endl;
}
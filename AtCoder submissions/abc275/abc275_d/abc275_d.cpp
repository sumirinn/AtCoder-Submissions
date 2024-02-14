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
//97~122(a~z),65~90(A~Z)

int main(){
    ll n; cin >> n;
    map<ll, ll> m;

    auto f = [&](auto f, ll n) ->ll {
        if(n==0) return 1;
        ll a = n / 2, b = n / 3;
        ll ans = 0;
        if(m.count(a)) ans += m[a];
        else ans += f(f, a);
        if(m.count(b)) ans += m[b];
        else ans += f(f, b);
        m[n] = ans;
        return ans;
    };

    ll answer = f(f, n);
    cout << answer << endl;
}
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
    ll n; cin >> n;

    unordered_map<ll, ll> memo;
    
    auto f = [&](auto f, ll x) -> ll {
        if(x==1) return 0;
        if(memo.count(x)) return memo[x];
        ll res = f(f, x/2) + f(f, x - x/2) + x;
        return memo[x] = res;
    };
    cout << f(f, n) << endl;
}
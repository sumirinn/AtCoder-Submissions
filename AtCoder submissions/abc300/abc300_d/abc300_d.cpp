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

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
        if (f[i]) continue;
        primes.push_back(i);
        f[i] = i;
        for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
            }
        }
    }
};

int main(){
    ll n; cin >> n;
    Sieve p(1e6);

    int ans = 0;
    int m = p.primes.size();
    repp(ai, m){
        ll a = p.primes[ai];
        if(a*a*a*a*a>n) break;
        for(int bi=ai+1; bi<m; bi++){
            ll b = p.primes[bi];
            if(a*a*b*b*b>n) break;
            for(int ci=bi+1; ci<m; ci++){
                ll c = p.primes[ci];
                if(a*a*b*c*c>n) break;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
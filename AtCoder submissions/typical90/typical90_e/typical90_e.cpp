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
using MP = map<int, vector<int>>;
//using mint = modint998244353;
using mint = modint1000000007;
using P = pair<int, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int main(){
    ll n; int b, k; cin >> n >> b >> k;
    vector<int> c(k);
    rep(i,k) cin >> c[i];

    auto mul =[&](vector<mint>& dpi, vector<mint>& dpj, int tj) -> vector<mint> {
        vector<mint> res (b, 0);
        rep(p,b)rep(q,b)res[(p * tj + q) % b] += dpi[p] * dpj[q];
        return res;
    };

    const int log = 62;
    vector<int> ten(log, 10);
    repp(i,log-1) ten[i] = (ten[i-1]*ten[i-1]) % b; 

    vector<vector<mint>> doubling(log, vector<mint>(b,0));
    rep(i,k) doubling[0][c[i]%b] += 1;
    repp(i, log-1) doubling[i] = mul(doubling[i-1], doubling[i-1], ten[i-1]);

    vector<mint> res(b, 0);
    res[0] = 1;
    rep(i,log) if(n & (1ll<<i)) res = mul(res, doubling[i], ten[i]);
    cout << res[0].val() << endl;
}
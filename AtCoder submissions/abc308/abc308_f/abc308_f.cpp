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
using P = pair<ll, ll>;
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
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
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    multiset<ll> p;
    rep(i, n){
        ll a; cin >> a;
        p.insert(a);
        ans += a;
    }
    vector<P> c(m);
    rep(i, m) cin >> c[i].second;
    rep(i, m) cin >> c[i].first;
    sort(c.rbegin(), c.rend());

    rep(i, m){
        ll d = c[i].first, l = c[i].second;
        auto itr = p.lower_bound(l);
        if(itr==p.end()) continue;
        p.erase(itr);
        ans -= d;
    }

    cout << ans << endl;
}

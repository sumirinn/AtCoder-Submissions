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
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a, b, c;
    rep(ni, n){
        int t, x;
        cin >> t >> x;
        if(t==0) a.push_back(x);
        if(t==1) b.push_back(x);
        if(t==2) c.push_back(x);
    }

    auto f = [&](vector<ll>& v) -> void{
        sort(v.rbegin(), v.rend());
        v.insert(v.begin(), 0);
        rep(i, v.size()-1) v[i+1] += v[i];
    };

    f(a); f(b); f(c);

    int na = a.size();
    int nb = b.size();
    int nc = c.size();

    vector<ll> mc(nb, m+1);
    rep(i, nc) chmin(mc[min<ll>(c[i], nb-1)], i);
    for(int i=nb-2; i>=0; i--) chmin(mc[i], mc[i+1]);

    ll ans = 0;
    rep(i, nb){
        int ai = m - i - mc[i];
        if(ai<0) break;
        ans = max(ans, a[min(ai, na-1)]+b[i]);
    }
    cout << ans << endl;
}
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
using mint = modint998244353;
using P = pair<ll, int>;
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

struct Edge {
    int a, b, c;
    Edge(){}
    Edge(int a, int b, int c): a(a), b(b), c(c) {}
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> es;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(a,b,c);
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    rep(i,k){
        int ei;
        cin >> ei;
        ei--;
        auto [a, b, c] = es[ei];
        dist[b] = min(dist[b], dist[a]+c);
    }

    ll ans = dist[n-1];
    if(ans==INF) ans = -1;
    cout << ans << endl;
}
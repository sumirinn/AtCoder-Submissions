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
using P = pair<int, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int & x, int y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> to(n);
    rep(mi,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    vector<vector<int>> dist(n, vector<int>(n,inf));
    queue<P> q;
    auto push = [&](int i, int j, int d){
        if(dist[i][j]!=inf) return;
        dist[i][j] = d;
        q.emplace(i, j);
    };
    push(0, n-1, 0);
    while(q.size()){
        auto [a,b] = q.front(); q.pop();
        int d = dist[a][b];
        for(int na : to[a]){
            for(int nb : to[b]){
                if(c[na]==c[nb]) continue;
                push(na, nb, d+1);
            }
        }
    }

    int ans = dist[n-1][0];
    if(ans==inf) ans = -1;
    cout << ans << endl;
};

int main(){
    int t;
    cin >> t;
    rep(ti, t) solve();
}
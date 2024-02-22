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
using P = pair<ll, int>;
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


struct Edge {
    int to, cost, id;
    Edge(int to, int cost, int id):
    to(to), cost(cost), id(id) {}

};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c, i+1);
        g[b].emplace_back(a, c, i+1);
    }

    vector<ll> dist(n, INF);
    vector<int> from(n, -1);
    priority_queue<P, vector<P>, greater<P>> q;
    dist[0] = 0;
    q.emplace(0, 0);
    while(!q.empty()){
        auto [d, v] = q.top(); q.pop();
        if(dist[v] != d) continue;
        for(auto [u, cost, id] : g[v]){
            if(dist[u]<= d+cost) continue;
            dist[u] = d + cost;
            from[u] = id;
            q.emplace(d+cost, u);
        }
    }

    repp(i, n-1) cout << from[i]  << " ";
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<vector<int>> bto(n);
    scc_graph g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        bto[v].pb(u);
        g.add_edge(u,v);
    }

    auto d = g.scc();
    int csiz = 0;
    vector<bool> st(n,false);
    for(auto es: d){
        bool ok = false;
        for(int e : es){
            if(e==0) ok = true;
        }
        if(ok){
            for(int e : es){
                st[e]= true;
            }
            csiz = es.size();
        }
    }
    int cnt = 0;
    rep(i,n) if(st[i]) cnt++;
    if(cnt==1){
        cout << -1 << endl;
        return 0;
    }

    vector<int> visited(n);
    vector<int> dist(n, inf);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : to[v]){
            if(dist[u]!=inf) continue;
            if(st[u]==false) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    vector<int> bvisited(n);
    vector<int> bdist(n, inf);
    queue<int> bq;
    bq.push(0);
    bdist[0] = 0;
    while(!bq.empty()){
        int v = bq.front();
        bq.pop();
        for(int u : bto[v]){
            if(bdist[u]!=inf) continue;
            if(st[u]==false) continue;
            bdist[u] = bdist[v] + 1;
            q.push(u);
        }
    }

    int ans = inf;
    rep(i,n)if(st[i]){
        if(i==0) continue;
        ans = min(ans,dist[i]+bdist[i]);
    }

    cout << ans << endl;
}
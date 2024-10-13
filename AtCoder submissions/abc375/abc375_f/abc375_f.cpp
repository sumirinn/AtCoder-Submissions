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
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int,int,ll>> edges;
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.eb(u,v,w);
    }

    vector<bool> blocked(m);
    vector<tuple<int,int,int>> qs;
    rep(qi,q){
        int type;
        cin >> type;
        if(type==1){
            int i;
            cin >> i;
            i--;
            blocked[i] = true;
            qs.eb(type,i,-1);
        }
        if(type==2){
            int x, y;
            cin >> x >> y;
            x--; y--;
            qs.eb(type,x,y);
        }
    }

    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m)if(!blocked[i]){
        auto [u,v,w] = edges[i];
        dist[u][v] = dist[v][u] = w;
    }
    rep(k,n)rep(i,n)rep(j,n){
        chmin(dist[i][j],dist[i][k]+dist[k][j]);
    }

    vector<ll> ans;
    for(int qi=q-1; qi>=0; qi--){
        auto [type,x,y] = qs[qi];
        if(type==1){
            auto [u,v,w] = edges[x];
            rep(i,n)rep(j,n){
                chmin(dist[i][j],dist[i][u]+w+dist[v][j]);
                chmin(dist[i][j],dist[i][v]+w+dist[u][j]);
            }
        }
        if(type==2) ans.pb(dist[x][y]);
    }

    reverse(ans.begin(),ans.end());
    for(ll val : ans){
        if(val==INF) val = -1;
        cout << val << endl;
    }
}
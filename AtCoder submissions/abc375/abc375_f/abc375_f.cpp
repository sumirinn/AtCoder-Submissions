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
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<vector<ll>> g(n,vector<ll>(n,INF));
    vector<pii> id(m);
    vector<ll> id2(m);
    rep(mi,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u][v] = w;
        g[v][u] = w;
        id[mi] = pii(u,v);
        id2[mi] = w;
    }

    vector<int> Q(q);
    vector<int> x(q,inf),y(q,inf);
    rep(i,q){
        cin >> Q[i];
        if(Q[i]==1){
            cin >> x[i];
            x[i]--;
            auto [u,v] = id[x[i]];
            g[u][v] = INF;
            g[v][u] = INF;
        }
        if(Q[i]==2){
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
    }

    vector<ll> ans;
    rep(i,n) g[i][i] = 0;
    rep(k,n)rep(i,n)rep(j,n){
        g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
    }

    for(int qi=q-1; qi>=0; qi--){
        if(Q[qi]==2){
            ll res = g[y[qi]][x[qi]];
            if(res==INF) res = -1;
            ans.pb(res); 
        }
        if(Q[qi]==1){
            auto[u,v] = id[x[qi]];
            ll w = id2[x[qi]];
            rep(i,n)rep(j,n){
                g[i][j] = min(g[i][j],g[i][u]+w+g[v][j]);
                g[i][j] = min(g[i][j],g[i][v]+w+g[u][j]);
            }
        }
    }

    reverse(ans.begin(),ans.end());
    for(ll z : ans) cout << z << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pil>> g(n);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    vector<ll> dist(n, INF), distn(n,INF);
    priority_queue<pli, vector<pli>,greater<pli>> pq;
    dist[0] = 0;
    pq.emplace(0,0);
    while(!pq.empty()){
        auto [d,v] = pq.top();
        pq.pop();
        if(dist[v]!=d) continue;
        for(auto [u, cost] : g[v]){
            if(dist[u]>dist[v]+cost){
                dist[u] = dist[v] + cost;
                pq.emplace(dist[u],u);
            }
        }
    }

    distn[n-1] = 0;
    pq.emplace(0,n-1);
    while(!pq.empty()){
        auto [d,v] = pq.top();
        pq.pop();
        if(distn[v]!=d) continue;
        for(auto [u, cost] : g[v]){
            if(distn[u]>distn[v]+cost){
                distn[u] = distn[v] + cost;
                pq.emplace(distn[u],u);
            }
        }
    }

    rep(i,n) cout << dist[i] + distn[i] << endl;
}
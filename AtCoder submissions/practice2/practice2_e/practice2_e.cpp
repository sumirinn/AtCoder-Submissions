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
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


const ll b = (ll)1<<40;

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];

    mcf_graph<int,ll> G(n*2+2);
    int st=n*2, gl=n*2+1;
    // 容量 1、コスト B - A[i][j]
    rep(i,n)rep(j,n) G.add_edge(i,j+n,1,b-a[i][j]);
    rep(i,n){
        // 容量 K, コスト 0
        G.add_edge(st,i,k,0);
        G.add_edge(i+n,gl,k,0);
    }
    // バイパス
    G.add_edge(st,gl,n*k,b);

    auto [max_flow, min_cost] = G.flow(st,gl,n*k);

    vector<string> grid(n,string(n,'.'));
    const auto &edges = G.edges();
    for(const auto &e : edges){
        if(e.from==st||e.to==gl||e.flow==0) continue;
        grid[e.from][e.to-n] = 'X';
    }

    cout << b*n*k - min_cost << endl;
    rep(i,n) cout << grid[i] << endl;
}
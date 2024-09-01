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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


using Edge = tuple<int,int,ll>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> es;
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(a,b,c);
        chmin(dist[a][b],c);
        chmin(dist[b][a],c);
    }

    rep(k,n)rep(i,n)rep(j,n){
        chmin(dist[i][j],dist[i][k]+dist[k][j]);
    }

    int q;
    cin >> q;
    rep(qi,q){
        int k;
        cin >> k;
        vector<int> ei(k);
        rep(i,k) cin >> ei[i], ei[i]--;

        ll ans = INF;
        do{
            rep(s,1<<k){
                ll now = 0;
                int v = 0;
                rep(i,k){
                    auto[a,b,c] = es[ei[i]];
                    if(s>>i&1) swap(a,b);
                    now += dist[v][a];
                    now += c;
                    v = b;
                }
                now += dist[v][n-1];
                chmin(ans,now);
            }
        }while(next_permutation(ei.begin(),ei.end()));
        cout << ans << endl;
    }
}
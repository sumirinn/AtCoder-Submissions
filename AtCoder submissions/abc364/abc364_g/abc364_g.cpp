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
using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct Edge{
    int to, cost;
    Edge(int to, int cost): to(to), cost(cost) {}
};


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Edge>> g(n);
    rep(mi,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }
    k--;
    int k2 = 1<<k;
    
    vector<vector<ll>> dp(k2,vector<ll>(n,INF));
    rep(s,k2){
        priority_queue<pli,vector<pli>,greater<pli>> q;
        rep(v,n){
            for(int ns=s; ns; ns=(ns-1)&s){
                chmin(dp[s][v],dp[ns][v]+dp[s^ns][v]);
            }
            if(v<k && s==(1<<v)) dp[s][v] = 0;
            q.emplace(dp[s][v],v);
        }
        while(!q.empty()){
            auto [d,v] = q.top();
            q.pop();
            if(dp[s][v]!=d) continue;
            for(auto e : g[v]){
                ll nd = d+e.cost;
                if(nd>=dp[s][e.to]) continue;
                dp[s][e.to] = nd;
                q.emplace(nd,e.to);
            }
        }
    }

    for(int v=k; v<n; v++) cout << dp[k2-1][v] << endl;
}
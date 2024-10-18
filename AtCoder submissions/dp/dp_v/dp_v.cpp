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
//using mint = modint998244353;
//using mint = modint1000000007;
using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(int& x, int y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(){
    int n; 
    ll m;
    cin >> n >> m;
    mint::set_mod(m);
    vector<vector<int>> to(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        to[v].pb(u);
    }

    vector<mint> dp(n);
    auto dfs1 =[&](auto dfs1, int now, int pre=-1)->void{
        dp[now] = 1;
        for(int nex : to[now]){
            if(nex==pre) continue;
            dfs1(dfs1,nex,now);
            dp[now] *= dp[nex]+1;
        }
    };

    vector<mint> ans(n);
    auto dfs2 =[&](auto dfs2, int now, int pre=-1)->void{
        ans[now] = 1;
        for(int nex : to[now]) ans[now] *= dp[nex] + 1;

        int ns = to[now].size();
        vector<mint> l(ns),r(ns);
        rep(i,ns) l[i] = r[i] = dp[to[now][i]] + 1;
        rep(i,ns-1) l[i+1] *= l[i];
        for(int i=ns-2; i>=0; i--) r[i] *= r[i+1];

        rep(nex,ns){
            if(to[now][nex]==pre) continue;
            dp[now] = 1;
            if(nex) dp[now] *= l[nex-1];
            if(nex+1<ns) dp[now] *= r[nex+1];
            dfs2(dfs2,to[now][nex],now);
        }
    };

    dfs1(dfs1,0);
    dfs2(dfs2,0);
    rep(i,n) cout << ans[i].val() << endl;
}
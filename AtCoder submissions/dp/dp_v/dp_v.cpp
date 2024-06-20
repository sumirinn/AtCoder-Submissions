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
//using mint = modint1000000007;
using mint = modint;
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
    int n; ll m;
    cin >> n >> m;
    mint::set_mod(m);
    vector<vector<int>> to(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<mint> dp(n);
    auto dfs1 =[&](auto dfs1, int v, int p=-1)->void{
        dp[v] = 1;
        for(int u : to[v]){
            if(u==p) continue;
            dfs1(dfs1,u,v);
            dp[v] *= dp[u] + 1;
        }
    };

    vector<mint> ans(n);
    auto dfs2=[&](auto dfs2, int v, int p=-1)->void{
        ans[v] = 1;
        for(int u : to[v]) ans[v] *= dp[u] + 1;

        int ns = to[v].size();
        vector<mint> l(ns), r(ns);
        rep(i,ns){
            l[i] = dp[to[v][i]] + 1;
            r[i] = dp[to[v][i]] + 1;
        }
        repp(i,ns-1) l[i] *= l[i-1];
        for(int i=ns-2; i>=0; i--) r[i] *= r[i+1];

        rep(i,ns){
            if(to[v][i]==p) continue;
            dp[v] = 1;
            if(i) dp[v] *= l[i-1];
            if(i+1<ns) dp[v] *= r[i+1];
            //cout << i << " " << dp[v].val() << endl;
            dfs2(dfs2,to[v][i], v);
        }
        
    };


    dfs1(dfs1,0);
    //cout << dp[0].val() << endl;
    dfs2(dfs2,0);

    rep(i,n) cout << ans[i].val() << endl;
}
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


int main(){
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        to[v].pb(u);
    }
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;
    vector<bool> used(n);
    vector<int> sz(n);
    auto cd =[&](auto cd, int v)->void{
        auto getCentroid =[&](){
            auto dfs =[&](auto f, int v, int p=-1)->int{
                sz[v] = 1;
                for(int u : to[v]){
                    if(u==p || used[u]) continue;
                    sz[v] += f(f,u,v);
                }
                return sz[v];
            };
            // tot=頂点数
            int tot = dfs(dfs,v);
            int c = -1;
            auto dfs2 =[&](auto f, int v, int p=-1)->void{
                bool ok = (tot-sz[v])*2<=tot;
                for(int u : to[v]){
                    if(u==p || used[u]) continue;
                    f(f,u,v);
                    if(sz[u]*2>tot) ok = false;
                }
                if(ok) c = v;
            };
            dfs2(dfs2,v);
            return c;
        };
        int c = getCentroid();

        used[c] = true;
        map<int,int> cnt;
        map<int,ll> sum;
        cnt[a[c]] = 1;
        sum[a[c]] = 0;
        for(int u : to[c]){
            if(used[u]) continue;
            vector<pii> ps;
            auto dfs =[&](auto f, int v, int p=-1, int dep=1)->void{
                ps.eb(a[v],dep);
                for(int u : to[v]){
                    if(u==p || used[u]) continue;
                    f(f,u,v,dep+1);
                }
            };
            dfs(dfs,u);
            for(auto [col,dep] : ps){
                ans += sum[col] + (ll)dep*cnt[col];
            }
            for(auto [col,dep] : ps){
                cnt[col]++;
                sum[col] += dep;
            }
        }
        
        for(int u : to[c]){
            if(used[u]) continue;
            cd(cd,u);
        }
    };
    cd(cd,0);

    cout << ans << endl;
}
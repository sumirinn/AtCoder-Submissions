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
using mint = modint1000000007;
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
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    vector<vector<int>> es(n,vector<int>(n,inf));
    int id = 0;
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        to[v].pb(u);
        es[u][v] = id;
        es[v][u] = id;
        id++;
    }

    int m;
    cin >> m;
    vector<vector<int>> ks(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        auto dfs =[&](auto dfs, int now, int pre)->int{
            if(now==v) return inf;
            for(int nex : to[now]){
                if(nex==pre) continue;
                int c = dfs(dfs,nex,now);
                if(c==inf){
                    ks[i].pb(es[now][nex]);
                    return inf;
                }
            }
            return 0;
        };
        dfs(dfs,u,-1);
    }

    ll ans = 0;
    int m2 = 1<<m;
    rep(s,m2){
        bool ok = true;
        vector<bool> vs(n-1,false);
        int cnt = 0;
        rep(i,m){
            if(s>>i&1){
                for(int e : ks[i]){
                    if(vs[e]==false){
                        cnt++;
                        vs[e] = true;
                    }
                }
            }
        }
        int nc = (n-1) - cnt;
        ll ncnt = (ll)1<<nc;
        if(__builtin_popcount(s)%2==0) ans += ncnt;
        else ans -= ncnt;
    }
    cout << ans << endl;
}
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
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


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

    vector<bool> used(n,false);
    vector<vector<int>> vs;
    rep(i,n){
        if(used[i]) continue;
        used[i] = true;
        if(to[i].size()!=3){
            continue;
        }
        vector<int> es;
        es.pb(i);
        auto dfs =[&](auto dfs, int now, int pre)->void{
            for(int nex : to[now]){
                if(used[nex]) continue;
                used[nex] = true;
                if(nex==pre) continue;
                if(to[nex].size()!=3) continue;
                es.pb(nex);
                dfs(dfs,nex,now);
            }
        };
        dfs(dfs,i,-1);
        vs.pb(es);
    }

    ll ans = 0;
    for(auto v : vs){
        ll cnt = 0;
        for(int now : v){
            for(int nex : to[now]) if(to[nex].size()==2) cnt++;
        }
        ans += c2(cnt);
    }
    cout << ans << endl;
}
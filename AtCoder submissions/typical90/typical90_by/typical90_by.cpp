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
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> ax(n), ay(n), bx(n), by(n);
    map<pll,int> mp;
    rep(i,n) cin >> ax[i] >> ay[i];
    rep(i,n){
        cin >> bx[i] >> by[i];
        mp[pll(bx[i],by[i])] = i+n;
    }

    mf_graph<int> g(n*2 + 2);
    rep(i,n)rep(j,8){
        ll tx = ax[i] + dx[j]*t;
        ll ty = ay[i] + dy[j]*t;
        if(mp[pll(tx,ty)]) g.add_edge(i,mp[pll(tx,ty)],1);
    }
    rep(i,n) g.add_edge(n*2,i,1);
    rep(i,n) g.add_edge(i+n,n*2+1,1);

    int res = g.flow(2*n, 2*n+1);
    if(res!=n){
        cout << "No" << endl;
        return 0;
    }

    vector<int> ans(n);
    for(auto e : g.edges()){
        if(e.flow==1){
            int u = e.from;
            int v = e.to;
            if(u>=n*2 || v>=n*2) continue;
            v -= n;
            rep(j,8){
                if(ax[u]+dx[j]*t==bx[v] && ay[u]+dy[j]*t==by[v]){
                    ans[u] = j + 1;
                }
            }
        }
    }

    cout << "Yes" << endl;
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
}
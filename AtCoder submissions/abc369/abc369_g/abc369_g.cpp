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


struct Edge{
    int to;
    ll cost;
    Edge() {}
    Edge(int to, ll cost):to(to),cost(cost) {}
};

int main(){
    int n;
    cin >> n;
    vector<vector<Edge>> g(n);
    rep(i,n-1){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    auto dfs =[&](auto dfs, int v, int p=-1)->multiset<ll>{
        multiset<ll> f;
        for(auto e : g[v]){
            if(e.to==p) continue;
            auto nf = dfs(dfs,e.to,v);

            ll x = *nf.rbegin();
            nf.erase(prev(nf.end()));
            nf.insert(x+e.cost);

            if(f.size()<nf.size()) swap(f,nf);
            for(ll el : nf) f.insert(el);
        }
        f.insert(0);
        return f;
    };

    auto f = dfs(dfs,0);
    vector<ll> as;
    for(ll x : f) as.pb(x);
    reverse(as.begin(),as.end());
    ll ans = 0;
    for(ll a : as){
        ans += a*2;
        cout << ans << endl;
    }
}
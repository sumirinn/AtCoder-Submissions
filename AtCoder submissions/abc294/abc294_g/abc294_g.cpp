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
#define mp make_pair
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
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


struct Edge {
    int to, cost, id;
    Edge() {}
    Edge(int to, int cost, int id): to(to), cost(cost), id(id) {}
};

int op(int a, int b) {return min(a,b);}
int rmq_e() {return 1e9;}

int main(){
    int n; 
    cin >> n;
    vector<vector<Edge>> g(n);
    rep(i,n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b,c,i);
        g[b].emplace_back(a,c,i);
    }

    vector<int> et;
    vector<int> in(n), out(n);
    vector<int> ein(n-1), eout(n-1), ew(n-1);
    auto Eular_Tour =[&](auto dfs, int v, int p=-1)->void{
        in[v] = et.size();
        et.push_back(v);
        for(auto e : g[v]){
            if(e.to==p) continue;
            ein[e.id] = et.size()-1;
            ew[e.id] = e.cost;
            dfs(dfs,e.to,v);
            eout[e.id] = et.size()-1;
            et.push_back(v);
        }
        out[v] = et.size();
    };
    Eular_Tour(Eular_Tour,0);

    segtree<int,op,rmq_e> rmq(et.size());
    rep(i,et.size()) rmq.set(i,in[et[i]]);
    fenwick_tree<ll> d(et.size());
    rep(i,n-1) d.add(ein[i],ew[i]);
    rep(i,n-1) d.add(eout[i],-ew[i]);

    int q;
    cin >> q;
    rep(qi,q){
        int type, a, b;
        cin >> type >> a >> b;
        if(type==1){
            a--;
            int dif = b - ew[a];
            ew[a] = b;
            d.add(ein[a],dif);
            d.add(eout[a],-dif);
        }
        if(type==2){
            a--; b--;
            int l=in[a], r=in[b];
            if(l>r) swap(l,r); 
            int c = et[rmq.prod(l,r+1)];
            ll ans = 0;
            if(a!=c) ans += d.sum(in[c],in[a]);
            if(b!=c) ans += d.sum(in[c],in[b]);
            cout << ans << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using db = double; 
using ull = unsigned long long;
using ld = long double; 
using bl = bool;
const int inf = 1001001001; 
const ll INF = 5e18;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>; using vvvvi = vv<vvi>;
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vdb = vc<db>; using vvdb = vv<db>; using vvvdb = vv<vdb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using vs = vc<string>; using vvs = vv<string>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define repp(i,n) for(ll i=1; i<=(n); i++)
#define drep(i,n) for(ll i=(n)-1; i>=0; i--)
#define nfor(i,s,n) for(ll i=s; i<n; i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
template<typename T> void chmax(T& x, T y) {x = max(x, y);}
template<typename T> void chmin(T& x, T y) {x = min(x, y);}
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define YN {cout << "Yes" << endl;}else{cout << "No" << endl;}
#define TKAK {cout << "Takahashi" << endl;}else{cout << "Aoki" << endl;}
#define next_p(v) next_permutation(v.begin(),v.end())
bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define fi first
#define se second
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint; //mint::set_mod(m);で定義できる
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
//using P = pair<db, int>;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct Edge{
    int to, id;
    ll cost;
    Edge(int to, ll cost, int id): to(to), cost(cost), id(id) {}
};

int main(){
    int n, m;
    cin >> n >> m;
    vv<Edge> g(n);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].emplace_back(v,w,i);
        g[v].emplace_back(u,w,i);
    }

    auto dijkstra =[&](int sv){
        vl dist(n,INF);
        pq_g<pli> q;
        dist[sv] = 0;
        q.emplace(0,sv);
        while(!q.empty()){
            auto [d,v] = q.top();
            q.pop();
            if(dist[v]!=d) continue;
            for(auto e : g[v]){
                ll nd = d + e.cost;
                if(dist[e.to]<=nd) continue;
                dist[e.to] = nd;
                q.emplace(nd,e.to);
            }
        }

        return dist;
    };

    auto dist1 = dijkstra(0);
    auto distN = dijkstra(n-1);

    rep(v,n){
        vector<Edge> ng;
        for(auto e : g[v]){
            if(dist1[v]+e.cost+distN[e.to]!=dist1[n-1]) continue;
            ng.pb(e); 
        }
        swap(g[v],ng);
    }

    vb onPath(m);
    {
        int v = 0;
        while(v!=n-1){
            onPath[g[v][0].id] = true;
            v = g[v][0].to;
        }
    }

    vl far(n);
    {
        vi vs(n);
        rep(i,n) vs[i] = i;
        sort(nall(vs),[&](int i, int j){
            return dist1[i] > dist1[j];
        });
        for(int v : vs){
            far[v] = dist1[v];
            for(auto e : g[v]){
                if(onPath[e.id]) continue;
                chmax(far[v],far[e.to]);
            }
        }
    }

    vb ans(m);
    {
        int v = 0;
        ll mx = 0;
        while(v!=n-1){
            mx = max(mx,far[v]);
            auto e = g[v][0];
            if(mx<dist1[e.to]) ans[e.id] = true;
            v = e.to;
        }
    }

    rep(i,m)if(ans[i]) YN;
}
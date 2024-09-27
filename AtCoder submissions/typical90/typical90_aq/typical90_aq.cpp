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
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct state{
    int x, y, dir;
    state(int x=0, int y=0, int dir=0): x(x), y(y), dir(dir) {}
};

int main(){
    int h, w;
    cin >> h >> w;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<vector<int>>> dist(h,vector<vector<int>>(w,vector<int>(4,inf)));
    deque<state> q;
    rep(v,4){
        dist[rs][cs][v] = 0;
        q.emplace_back(rs,cs,v);
    }
    while(!q.empty()){
        auto [i,j,dir] = q.front();
        q.pop_front();
        rep(v,4){
            int ni=i+di[v], nj=j+dj[v];
            int cost=dist[i][j][dir] + (dir!=v ? 1 : 0);
            if(ni<0||nj<0||ni>=h||nj>=w) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj][v]<=cost) continue;
            dist[ni][nj][v] = cost;
            if(dir!=v) q.emplace_back(ni,nj,v);
            else q.emplace_front(ni,nj,v);
        }
    }

    int ans = inf;
    rep(v,4) ans = min(ans,dist[rt][ct][v]);
    cout << ans << endl;

}
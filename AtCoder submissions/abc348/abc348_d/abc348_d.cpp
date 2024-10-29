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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    int n;
    cin >> n;
    vector<vector<int>> ep(h,vector<int>(w,0));
    rep(i,n){
        int r, c, e;
        cin >> r >> c >> e;
        r--; c--;
        ep[r][c] = e;
    }

    int sx, sy;
    int gx, gy;
    rep(i,h)rep(j,w){
        if(a[i][j]=='S'){
            sx = i;
            sy = j;
        }
        if(a[i][j]=='T'){
            gx = i;
            gy = j;
        }
    }

    using P = pair<int,pii>;
    priority_queue<P> q;
    q.push(P(ep[sx][sy],pii(sx,sy)));
    vector<vector<int>> es(h,vector<int>(w,-1));
    es[sx][sy] = ep[sx][sy];
    while(!q.empty()){
        auto [e,r] = q.top();
        auto [i,j] = r;
        q.pop();
        if(es[i][j]!=e) continue;
        rep(v,4){
            int ni=i+di[v], nj=j+dj[v];
            if(ni<0||nj<0||ni>=h||nj>=w) continue;
            if(a[ni][nj]=='#') continue;
            if(es[ni][nj]>=e-1) continue;
            int ne = max(e-1,ep[ni][nj]);
            es[ni][nj] = ne;
            ep[ni][nj] = 0;
            q.push(P(ne,pii(ni,nj)));
        }
    }

    if(es[gx][gy]!=-1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
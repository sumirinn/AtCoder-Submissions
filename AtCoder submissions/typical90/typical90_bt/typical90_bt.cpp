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
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];

    vector<vector<bool>> used(h,vector<bool>(w,false));
    auto dfs =[&](auto dfs, int sx, int sy, int px, int py)->int{
        if(sx==px && sy==py && used[px][py]) return 0;
        used[px][py] = true;

        int res = -inf;
        rep(v,4){
            int nx=px+di[v], ny=py+dj[v];
            if(nx<0||ny<0||nx>=h||ny>=w) continue;
            if(c[nx][ny]=='#') continue;
            if((sx!=nx||sy!=ny) && used[nx][ny]) continue;
            int u = dfs(dfs,sx,sy,nx,ny);
            res = max(res,u+1);
        }
        used[px][py] = false;
        return res;
    };

    int ans = -1;
    rep(i,h)rep(j,w) ans = max(ans,dfs(dfs,i,j,i,j));
    if(ans<=2) ans = -1;
    cout << ans << endl;
}
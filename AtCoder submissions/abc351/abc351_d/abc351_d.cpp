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
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            rep(v,4){
                int ni=i+di[v], nj=j+dj[v];
                if(ni<0||nj<0||ni>=h||nj>=w) continue;
                if(s[ni][nj]=='#') continue;
                s[ni][nj] = '!';
            }
        }
    }

    int ans = 1;
    int n = h*w;
    dsu uf(n);
    vector<vector<int>> to(n);
    rep(i,h)rep(j,w){
        if(s[i][j]!='.') continue;
        rep(v,4){
            int ni=i+di[v], nj=j+dj[v];
            if(ni<0||nj<0||ni>=h||nj>=w) continue;
            if(s[ni][nj]!='.') continue;
            to[i*w+j].push_back(ni*w+nj);
            uf.merge(i*w+j,ni*w+nj);
        }
    }

    vector<bool> used(n);
    vector<bool> visited(n);

    rep(i,h)rep(j,w){
        if(s[i][j]!='.') continue;
        int start = uf.leader(i*w+j);
        if(used[start]) continue;
        used[start] = true;
        set<int> cnt;
        auto dfs = [&](auto dfs, int v)->void{
            visited[v] = true;
            int ii=v/w, jj=v%w;
            rep(d,4){
                int ni=ii+di[d], nj=jj+dj[d];
                if(ni<0||nj<0||ni>=h||nj>=w) continue;
                if(s[ni][nj]=='!') cnt.insert(ni*w+nj);
            }
            for(int u : to[v]){
                if(visited[u]) continue;
                dfs(dfs, u);
            }
        };
        dfs(dfs, start);
        ans = max(ans, (int)cnt.size()+uf.size(start));
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
//auto nex = calc_next で取得すると楽。
vector<vector<int> > calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int> > res(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<string, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
struct Edge {
    int u, v;
    ll w;
    Edge(){}
    Edge(int u, int v, ll w): u(u), v(v), w(w){}
};
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> dist(h,vector<int>(w,inf));

    queue<pii> q;
    rep(i,h)rep(j,w){
        if(s[i][j]=='S'){
            q.emplace(i,j);
            dist[i][j] = 0;
        }
    }
    vector<vector<pii>> warps(256);
    rep(i,h)rep(j,w){
        warps[s[i][j]].emplace_back(i,j);
    }

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(s[i][j]=='G'){
            cout << dist[i][j] << endl;
            return 0;
        }
        rep(v,4){
            int ni=i+di[v], nj=j+dj[v];
            if(ni<0||nj<0||ni>=h||nj>=w) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]!=inf) continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.emplace(ni,nj);
        }

        if(islower(s[i][j])){
            for(pii p : warps[s[i][j]]){
                int ni=p.first, nj=p.second;
                if(dist[ni][nj]!=inf) continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni,nj);
            }
            warps[s[i][j]] = vector<pii>();
        }
    }

    cout << -1 << endl;
}
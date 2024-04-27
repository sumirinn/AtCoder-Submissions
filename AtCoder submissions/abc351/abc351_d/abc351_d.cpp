#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
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
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
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
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            rep(d,4){
                int ni=i+di[d], nj=j+dj[d];
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
        rep(d,4){
            int ni=i+di[d], nj=j+dj[d];
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
        chmax(ans, cnt.size()+uf.size(start));
    }
    //rep(i,n) cout << i << " " << uf.size(i) << endl;

    cout << ans << endl;
}
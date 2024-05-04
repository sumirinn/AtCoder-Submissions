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
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

const int mx = 1505;
bool ligth[mx][mx];
bool wall[mx][mx];
bool ok[mx][mx];
int h, w, n, m;

bool visited[mx][mx];
bool memo[mx][mx];
bool f(int v, int i, int j) {
    if(i<0 || j<0 || i>=h || j>=w) return false;
    if(wall[i][j]) return false;
    if(ligth[i][j]) return true;
    if(visited[i][j]) return memo[i][j];
    visited[i][j] = true;
    return memo[i][j] = f(v, i+di[v], j+dj[v]);
}


int main(){
    cin >> h >> w >> n >> m;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        r--; c--;
        ligth[r][c] = true;
    }
    rep(i,m){
        int r, c;
        cin >> r >> c;
        r--; c--;
        wall[r][c] = true;
    }

    rep(v,4){
        rep(i,h)rep(j,w) visited[i][j] = false;
        rep(i,h)rep(j,w)if(f(v,i,j)) ok[i][j] = true;
    }

    int ans = 0;
    rep(i,h)rep(j,w)if(ok[i][j]) ans++;
    cout << ans << endl;
}
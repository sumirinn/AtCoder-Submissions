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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

struct e {
    int to; ll t, k;
    e(int to, ll t, ll k):
    to(to), t(t), k(k){}
};

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    //cout << x << endl;
    vector<vector<e>> to(n);
    rep(i,m){
        int a, b;
        ll t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        to[a].emplace_back(b,t,k);
        to[b].emplace_back(a,t,k);
    }

    priority_queue<pli, vector<pli>, greater<pli>> q;
    vector<ll> dist(n, INF);
    dist[x] = 0;
    q.push(pli(dist[x], x));
    while(!q.empty()){
        int v = q.top().second;
        ll T = q.top().first;
        q.pop();
        if(dist[v]!=T) continue;
        for(auto u : to[v]){
            ll nt = (dist[v]+u.k-1)/u.k*u.k + u.t;
            if(dist[u.to]>nt){
                dist[u.to] = nt;
                q.push(pli(dist[u.to], u.to));
            }
        } 
    }

    //rep(i,n) cout << dist[i] << endl;

    if(dist[y]==INF) dist[y] = -1;
    cout << dist[y] << endl;

}
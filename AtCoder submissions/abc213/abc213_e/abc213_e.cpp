#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
using ll = long long; using db = double;
using pii = pair<int, int>; using pll = pair<ll, ll>;  using pdd = pair<double, double>;
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
    
    deque<pii> q;
    vector<vector<int>> dist(h, vector<int>(w,inf));
    dist[0][0] = 0;
    q.emplace_back(0,0);
    while(!q.empty()){
        auto[i,j] = q.front();
        q.pop_front();
        //if(dist[i][j]!=inf) continue;
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]<=dist[i][j]) continue;
            dist[ni][nj] = dist[i][j];
            q.emplace_front(ni,nj);
        }
        rep2(ei,-2,2){
            rep2(ej,-2,2){
                if(abs(ei)+abs(ej)>3) continue;
                int ni = i+ei, nj = j+ej;
                if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
                if(dist[ni][nj]<=dist[i][j]+1) continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace_back(ni,nj);
            }
        }
    }

    cout << dist[h-1][w-1] << endl;
}
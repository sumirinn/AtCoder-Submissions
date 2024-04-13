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
//using mint = modint998244353;
using mint = modint1000000007;
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
    int n;
    cin >> n;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    int st = sx*n + sy;
    int g = gx*n + gy;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int m = n*n;
    vector<vector<pii>> to(m*2);
    rep(i,m){
        to[i].emplace_back(i+m,1);
        to[i+m].emplace_back(i,1);
    }

    rep(i,2*n-1){
        int sx1 = max(n-1-i,0), sy1 = max(0,i-n+1);
        while(sx1+1<n&&sy1+1<n){
            if(s[sx1][sy1]!='#'&&s[sx1+1][sy1+1]!='#'){
                to[sx1*n+sy1].emplace_back((sx1+1)*n+sy1+1, 0);
                to[(sx1+1)*n+sy1+1].emplace_back(sx1*n+sy1, 0);
            }
            sx1++; sy1++;
        }
        int sx2 = max(0,i-n+1), sy2 = min(i, n-1);
        while(sx2+1<n&&sy2-1>=0){
            if(s[sx2][sy2]!='#'&&s[sx2+1][sy2-1]!='#'){
                to[sx2*n+sy2+m].emplace_back((sx2+1)*n+sy2-1+m,0);
                to[(sx2+1)*n+sy2-1+m].emplace_back(sx2*n+sy2+m,0);
            }
            sx2++; sy2--;
        }
    }

    int ans = inf;

    rep(rp,2){
        vector<int> dist(m*2, inf);
        if(rp==1) st += m;
        dist[st] = 0;
        deque<int> q;
        q.push_back(st);
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            for(auto[u,d] : to[v]){
                if(dist[u]!=inf) continue;
                dist[u] = dist[v] + d;
                if(d==0) q.push_front(u);
                if(d==1) q.push_back(u);
            }
        }

        chmin(ans, dist[g]);
        chmin(ans, dist[g+m]);
    }

    ans++;
    if(ans>=inf) ans = -1;
    cout << ans << endl;
}
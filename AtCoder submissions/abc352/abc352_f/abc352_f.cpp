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
using C = complex<double>;
C inC(){
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int pc(int x) {return __builtin_popcount(x);}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b,-c);
        g[b].emplace_back(a,c);
    }

    vector<bool> used(n);
    vector<int> idx(n);
    vector<vector<int>> vs;
    vector<int> xs;
    rep(i,n)if(!used[i]){
        auto dfs = [&](auto dfs, int v) -> void {
            vs.back().push_back(v);
            used[v] = true;
            for(auto [u,c] : g[v]){
                if(used[u]) continue;
                idx[u] = idx[v] + c;
                dfs(dfs,u);
            }
        };
        vs.push_back(vector<int>());
        dfs(dfs,i);
        int mn = 0;
        for(int v : vs.back()) mn = min(mn,idx[v]);
        for(int v : vs.back()) idx[v] -= mn;
        int x = 0;
        for(int v : vs.back()) x |= 1<<idx[v];
        xs.push_back(x);
    }

    int n2 = 1<<n;
    m = xs.size();
    vector<int> ans(n,-1);
    rep(k,m){
        vector<bool> dp(n2);
        dp[0] = true;
        int num = 0;
        rep(i,m)if(i!=k){
            rep(s,n2) if(pc(s)==num && dp[s]){
                int x = xs[i];
                while(x<n2){
                    if((s&x)==0) dp[s|x] = true;
                    x <<= 1;
                }
            }
            num += vs[i].size();
        }

        int x = xs[k], cnt = 0;
        int offset = 0, i = 0;
        while(x<n2){
            if(dp[(n2-1)^x]){
                offset = i;
                cnt++;
            }
            x <<= 1;
            i++;
        }
        if(cnt==1){
            for(int v : vs[k]) ans[v] = offset + idx[v] + 1;
        }
    }

    rep(i,n) cout << ans[i] << " ";
    cout << endl;
}
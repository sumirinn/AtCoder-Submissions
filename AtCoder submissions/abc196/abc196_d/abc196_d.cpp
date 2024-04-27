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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    swap(a,b);

    int ans = 0;
    vector<vector<bool>> d(h,vector<bool>(w,false));
    auto dfs = [&](auto dfs, int prea, int preb) -> void{
        int si=-1, sj=-1;
        bool ok = false;
        rep(i,h)rep(j,w){
            if(ok) continue;
            if(d[i][j]) continue;
            si = i; sj = j;
            ok = true;
        }

        if(si==-1){
            ans++;
            return;
        }

        //1-1
        if(prea>0){
            d[si][sj] = true;
            dfs(dfs,prea-1, preb);
            d[si][sj] = false;
        }
        //2-1
        if(preb>0 && si+1<h){
            if(!d[si+1][sj]){
                d[si][sj] = true;
                d[si+1][sj] = true;
                dfs(dfs,prea,preb-1);
                d[si][sj] = false;
                d[si+1][sj] = false;
            }
        }
        //1-2
        if(preb>0 && sj+1<w){
            if(!d[si][sj+1]){
                d[si][sj] = true;
                d[si][sj+1] = true;
                dfs(dfs,prea,preb-1);
                d[si][sj] = false;
                d[si][sj+1] = false;
            }
        }
        return;
    };

    dfs(dfs,a,b);
    cout << ans << endl;
}
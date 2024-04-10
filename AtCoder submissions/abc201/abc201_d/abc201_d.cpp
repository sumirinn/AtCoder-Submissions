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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    vector<vector<int>> dp(h,vector<int>(w, -inf));
    dp[h-1][w-1] = 0;
    for(int i=h-1; i>=0; i--){
        for(int j=w-1; j>=0; j--){
            if((i+j+1)%2==0){
                int p = 0;
                if(a[i][j]=='+') p = 1;
                else p = -1;
                if(i-1>=0) chmax(dp[i-1][j],-dp[i][j]+p);
                if(j-1>=0) chmax(dp[i][j-1],-dp[i][j]+p);
            }
            if((i+j+1)%2==1){
                int p = 0;
                if(a[i][j]=='+') p = 1;
                else p = -1;
                if(i-1>=0) chmax(dp[i-1][j],-dp[i][j]+p);
                if(j-1>=0) chmax(dp[i][j-1],-dp[i][j]+p);
            }
        }
    }

    if(dp[0][0]>0) cout << "Takahashi" << endl;
    else if(dp[0][0]==0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
}
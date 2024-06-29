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
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    map<int,vector<int>> mp;
    rep(i,m){
        x[i]--;
        mp[x[i]].push_back(i);
    }

    int m2 = 1<<m;
    vector<vector<mint>> dp(n+1,vector<mint>(m2));
    dp[0][m2-1] = 1;
    rep(i,n){
        rep(j,m2){
            rep(k,m){
                if(!(j&1<<k)) continue;
                int ps = j;
                ps -= 1<<k;
                for(int nex : mp[k]){
                    ps |= 1<<nex;
                }
                dp[i+1][ps] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    rep(j,m2) ans += dp[n][j];
    cout << ans.val() << endl;
}
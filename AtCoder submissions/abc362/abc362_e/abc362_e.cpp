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
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<vector<mint>>> dp(n+1,vector<vector<mint>>(n+1,vector<mint>(n+1)));

    rep(i,n){
        if(i==0) continue;
        rep(j,i) dp[i][j][2] = 1;
        rep(j,i)rep(k,n){
            mint now = dp[i][j][k];
            if(now==0) continue;
            for(int x=i+1; x<n; x++){
                if(a[x]-a[i]==a[i]-a[j]){
                    dp[x][i][k+1] += now;
                }
            }
        }
    }

    vector<mint> ans(n+1);
    ans[1] = n;
    for(int k=2; k<=n; k++){
        rep(i,n)rep(j,i) ans[k] += dp[i][j][k];
    }
    repp(i,n) cout << ans[i].val() << " ";
    cout << endl;
}
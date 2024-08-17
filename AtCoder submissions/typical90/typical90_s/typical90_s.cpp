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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n;
    cin >> n;
    int n2 = n*2;
    vector<int> a(n2);
    rep(i,n2) cin >> a[i];

    vector<vector<int>> dp(n2,vector<int>(n2,inf));
    rep(l,n2-1) dp[l][l+1] = abs(a[l]-a[l+1]);
    for(int len=3; len<n2; len+=2){
        for(int start=0; start+len<n2; start++){
            int l = start;
            int r = start + len;
            for(int k=l+1; k+1<r; k+=2) chmin(dp[l][r], dp[l][k]+dp[k+1][r]);
            chmin(dp[l][r], dp[l+1][r-1]+abs(a[l]-a[r]));
        }
    }

    cout << dp[0][n2-1] << endl;
}
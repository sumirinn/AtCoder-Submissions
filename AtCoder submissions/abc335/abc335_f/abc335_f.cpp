#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using MP = map<int, vector<int>>;
using mint = modint998244353;
//using mint = modint1000000007;
using P = pair<int , int>;
void chmax(double& x, double y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
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
//comb(n,k)でnCkになる。
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*n), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*invs(n)), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
}
//素数判定  
bool isPrime(int x){
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}
//97~122(a~z),65~90(A~Z)

const int D = 400;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<mint>> s(D, vector<mint>(n));
    vector<mint> dp(n);
    dp[0] = 1;
    rep(i,n){
        //sの遷移O(√n)
        rep(j,D){
            dp[i] += s[j][i];
            if(i+j<n) s[j][i+j] += s[j][i];
        }
        //a[i]が小さいとき、sで移動O(√n)
        if(a[i]<D){
            if(i+a[i]<n) s[a[i]][i+a[i]] += dp[i];
        }
        //a[i]が大きいとき、愚直O(√n)
        else{
            for(int j=i+a[i]; j<n; j+=a[i]){
                dp[j] += dp[i];
            }
        }
    }

    mint ans = 0;
    rep(i,n) ans += dp[i];
    cout << ans.val() << endl;
}
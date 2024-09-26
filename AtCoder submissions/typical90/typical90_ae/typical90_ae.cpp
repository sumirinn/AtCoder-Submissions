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
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    const int s = 51;
    const int t = 1276;
    vector<vector<int>> g(s,vector<int>(t,0));
    rep(i,s)rep(j,t){
        vector<bool> m(t,true);
        if(i>=1) m[g[i-1][j+i]] = false;
        if(j>=2) repp(k,j/2) m[g[i][j-k]] = false;
        rep(k,t)if(m[k]){
            g[i][j] = k;
            break;
        }
    }


    int n;
    cin >> n;
    vector<int> w(n), b(n);
    rep(i,n) cin >> w[i];
    rep(i,n) cin >> b[i];
    
    int ans = 0;
    rep(i,n) ans ^= g[w[i]][b[i]];
    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
}
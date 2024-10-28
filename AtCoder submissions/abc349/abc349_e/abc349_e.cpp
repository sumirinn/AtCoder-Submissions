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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n = 3;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    vector<vector<int>> b(n,vector<int>(n,0));

    auto dfs=[&](auto dfs, int t)->bool{
        bool end = true;
        rep(i,n)rep(j,n)if(b[i][j]==0) end = false;
        if(end){
            ll res = 0;
            rep(i,n)rep(j,n) res += a[i][j]*b[i][j];
            if(res>0) return false;
            else return true;
        }

        rep(i,n)rep(j,n){
            if(b[i][j]!=0) continue;
            b[i][j] = t;
            bool ok = false;
            if(b[i][j]==b[i][(j+1)%3]&&b[i][(j+1)%3]==b[i][(j+2)%3]) ok = true;
            if(b[i][j]==b[(i+1)%3][j]&&b[(i+1)%3][j]==b[(i+2)%3][j]) ok = true;
            if(b[0][0]==b[1][1]&&b[1][1]==b[2][2]&&b[0][0]!=0) ok = true;
            if(b[0][2]==b[1][1]&&b[1][1]==b[2][0]&&b[0][2]!=0) ok = true;
            if(dfs(dfs,-t)==false) ok = true;
            b[i][j] = 0;
            if(ok) return true;
        }
        return false;
    };
    if(dfs(dfs,1)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
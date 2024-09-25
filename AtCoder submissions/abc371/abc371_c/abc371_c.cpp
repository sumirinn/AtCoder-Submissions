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
    int n, mg, mh;
    cin >> n;
    vector<vector<bool>> g(n,vector<bool>(n,false)), h(n,vector<bool>(n,false));
    cin >> mg;
    rep(mi,mg){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = true;
        g[v][u] = true;
    }
    cin >> mh;
    rep(mi,mh){
        int u, v;
        cin >> u >> v;
        u--; v--;
        h[u][v] = true;
        h[v][u] = true;
    }

    vector<vector<int>> a(n,vector<int>(n,0));
    rep(i,n-1)rep(j,n-i-1){
        cin >> a[i][j+i+1];
        a[j+i+1][i] = a[i][j+i+1];
    }

    int ans = inf;
    vector<int> p(n);
    rep(i,n) p[i] = i;
    do{
        int nans = 0;
        rep(i,n)rep(j,n) if(g[p[i]][p[j]]!=h[i][j]) nans += a[i][j];
        nans /= 2;
        ans = min(ans,nans);
    }while(next_permutation(p.begin(),p.end()));

    cout << ans << endl;
}
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
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(int& x, int y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(){
    int n;
    ll k;
    cin >> n >> k;
    int d = 60;
    using vvm = vector<vector<mint>>;
    vector<vvm> a(d+1,vvm(n,vector<mint>(n,0)));
    rep(i,n)rep(j,n){
        int x;
        cin >> x;
        a[0][i][j] = x;
    }

    rep(s,d){
        rep(i,n)rep(j,n)rep(k,n){
            a[s+1][i][j] += a[s][i][k]*a[s][k][j];
        }
    }

    vvm ans(n,vector<mint>(n,0));
    rep(i,n) ans[i][i] = 1;
    rep(s,d+1)if(k>>s&1){
        vvm pre(n,vector<mint>(n,0));
        swap(pre,ans);
        rep(i,n)rep(j,n)rep(k,n){
            ans[i][j] += pre[i][k]*a[s][k][j];
        }
    }

    mint answer = 0;
    rep(i,n)rep(j,n) answer += ans[i][j];
    cout << answer.val() << endl;
}
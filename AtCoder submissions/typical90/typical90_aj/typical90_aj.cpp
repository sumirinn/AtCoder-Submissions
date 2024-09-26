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
    int n, Q;
    cin >> n >> Q;
    ll mx=INF, my=INF, Mx=-INF, My=-INF;
    vector<ll> x(n), y(n);
    rep(i,n){
        ll X, Y;
        cin >> X >> Y;
        x[i] = X + Y;
        y[i] = Y - X;
        mx = min(mx,x[i]);
        my = min(my,y[i]);
        Mx = max(Mx,x[i]);
        My = max(My,y[i]);
    }

    rep(qi,Q){
        int q;
        cin >> q;
        q--;
        ll a1 = abs(x[q]-mx);
        ll a2 = abs(x[q]-Mx);
        ll a3 = abs(y[q]-my);
        ll a4 = abs(y[q]-My);
        cout << max({a1,a2,a3,a4}) << endl;
    }
}
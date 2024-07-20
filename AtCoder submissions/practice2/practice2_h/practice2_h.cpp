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
    ll d;
    cin >> n >> d;
    two_sat ts(n*2);
    rep(i,n) ts.add_clause(i,true,i+n,true);
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    auto f =[&](ll a, ll b)->bool{
        if(abs(a-b)<d) return true;
        else return false;
    };

    rep(i,n)rep(j,n){
        if(i<=j) continue;
        if(f(x[i],x[j])) ts.add_clause(i,false,j,false);
        if(f(x[i],y[j])) ts.add_clause(i,false,j+n,false);
        if(f(y[i],x[j])) ts.add_clause(i+n,false,j,false);
        if(f(y[i],y[j])) ts.add_clause(i+n,false,j+n,false);
    }

    if(ts.satisfiable()) cout << "Yes" << endl;
    else{
        cout << "No" << endl;
        return 0;
    }

    auto ans = ts.answer();
    rep(i,n){
        if(ans[i]) cout << x[i] << endl;
        else cout << y[i] << endl;
    }

}
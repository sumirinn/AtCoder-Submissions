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

mt19937_64 rnd(58);

// prime
const ull mod = (1ll<<61) - 1;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    
    const int MX = 200005;
    vector<ull> h(MX);
    rep(i,MX) h[i] = rnd()%mod;

    vector<ull> sa(n+1), sb(n+1);
    rep(i,n) sa[i+1] = (sa[i]+h[a[i]])%mod;
    rep(i,n) sb[i+1] = (sb[i]+h[b[i]])%mod;

    rep(qi,q){
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        la--; lb--;
        if((sa[ra]-sa[la]+mod)%mod==(sb[rb]-sb[lb]+mod)%mod){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
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
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, k;
    ll p;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];

    auto g =[&](ll lens)->int{
        vector<vector<ll>> d(n,vector<ll>(n));
        rep(i,n)rep(j,n){
            if(a[i][j]==-1) d[i][j] = lens;
            else d[i][j] = a[i][j];
        }

        rep(s,n)rep(i,n)rep(j,n){
            chmin(d[i][j], d[i][s]+d[s][j]);
        }

        int cnt = 0;
        rep(i,n)for(int j=i+1; j<n; j++){
            if(d[i][j]<=p) cnt++;
        }
        return cnt;
    };

    auto f =[&](long long cnts) {
	long long cl = 1, cr = 5000000000LL, cm, minx = 5000000000LL;
	for (int i = 0; i < 40; i++) {
		cm = (cl + cr) / 2LL;
		int res = g(cm);
		if (res <= cnts) { cr = cm; minx = min(minx, cm); }
		else { cl = cm; }
	}
	return minx;
};

    ll l=f(k), r=f(k-1);
    if(r-l>=2000000000LL) cout << "Infinity" << endl;
    else cout << r - l << endl;
}
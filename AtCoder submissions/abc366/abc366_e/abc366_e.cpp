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
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


const int M = 1e6;

vector<ll> f(vector<int> x){
    int n = x.size();
    rep(i,n) x[i] += M*2;
    ll s = 0;
    rep(i,n) s += x[i];
    vector<ll> res(M*4+1);
    res[0] = s;

    int k = 0;
    sort(x.begin(),x.end());
    repp(i,M*4){
        while(k<n && x[k]<i) k++;
        s -= n - k*2;
        res[i] = s;
    }

    return res;
}


int main(){
    int n;
    ll d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    vector<ll> a = f(x);
    vector<ll> b = f(y);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll ans = 0;
    int j = b.size() - 1;
    rep(i,a.size()){
        while(j>=0 && a[i]+b[j]>d) j--;
        ans += j+1;
    }

    cout << ans << endl;
}
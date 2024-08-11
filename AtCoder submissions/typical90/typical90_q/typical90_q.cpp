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


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i,m) cin >> l[i] >> r[i];

    fenwick_tree<ll> t(n+2);
    vector<ll> v1(n+1,0), v2(n+1,0), v3(n+1,0);

    ll ans1 = 0;
    rep(i,m) v3[l[i]]++;
    rep(i,m) v3[r[i]]++;
    repp(i,n) ans1 += v3[i]*(v3[i]-1) / 2;

    ll ans2 = 0;
    rep(i,m) v1[r[i]]++;
    rep(i,n) v1[i+1] += v1[i];
    rep(i,m) v2[l[i]-1]++;
    repp(i,n) ans2 += v1[i]*v2[i];

    vector<pii> v;
    rep(i,m) v.eb(r[i],l[i]);
    sort(v.begin(),v.end());
    ll ans3 = 0;
    for(auto [R,L] : v){
        ans3 += t.sum(L+1,R+1);
        t.add(L,1);
    }

    ll tot = (ll)m*(m-1) / 2;
    cout << tot - (ans1 + ans2 + ans3) << endl;
}
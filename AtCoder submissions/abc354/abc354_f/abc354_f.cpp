#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
//auto nex = calc_next で取得すると楽。
vector<vector<int> > calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int> > res(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<string, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
struct Edge {
    int u, v;
    ll w;
    Edge(){}
    Edge(int u, int v, ll w): u(u), v(v), w(w){}
};
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

int op(int a, int b){return max(a,b);}
int e() {return 0;}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    {
        CC<int> cc;
        rep(i,n) cc.add(a[i]);
        rep(i,n) a[i] = cc(a[i]);
    }

    auto get = [&](){
        vector<int> dp(n);
        segtree<int, op, e> t(n);
        rep(i,n){
            dp[i] = t.prod(0,a[i]) + 1;
            t.set(a[i],dp[i]);
        }
        return dp;
    };

    vector<int> dl = get();
    rep(i,n) a[i] = n-1-a[i];
    reverse(a.begin(),a.end());
    vector<int> dr = get();
    reverse(dr.begin(),dr.end());

    int lis = *max_element(dl.begin(),dl.end());
    vector<int> ans;
    rep(i,n){
        if(dl[i]+dr[i]-1==lis) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i : ans) cout << i + 1 << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
}
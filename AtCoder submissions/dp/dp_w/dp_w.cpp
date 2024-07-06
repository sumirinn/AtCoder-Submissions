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

using S = ll;
using F = ll;
S op(S a, S b){return max(a,b);}
S e(){return 0;}//<-ここ、なんで-INFじゃないの????
S mapping(F f, S x){return f+x;}
F composition(F f, F g){return f+g;}
F id(){return 0;}

using pil = pair<int, ll>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pil>> p(n);
  rep(i,m){
    int l, r;
    ll a;
    cin >> l >> r >> a;
    l--; r--;
    p[r].emplace_back(l,a);
  }

  lazy_segtree<S,op,e,F,mapping,composition,id> dp(n);
  rep(r,n){
    ll pre = dp.prod(0,r);
    dp.set(r,pre);
    for(auto x : p[r]){
      auto [l,a] = x;
      dp.apply(l,r+1,a);
    }
  }

  ll ans = max((ll)0,dp.all_prod());
  cout << ans << endl;
}
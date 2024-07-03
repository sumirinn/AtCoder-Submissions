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


struct S{
    int val, y;
    S(int val=0, int y=-1): val(val), y(y) {}
};

S op(S a, S b){
    if(a.val>b.val) return a;
    if(a.val<b.val) return b;
    if(a.y<b.y) return a;
    return b;
}

S e(){return S();}

S mapping(int f, S x){
    x.val += f;
    return x;
}

int composition(int f, int g){return f+g;}

int id(){return 0;}

struct Rect {
    int lx, rx, ly, ry;
    Rect(int lx=0, int rx=0, int ly=0, int ry=0): lx(lx), rx(rx), ly(ly), ry(ry) {}
};

struct Event {
    int l, r, val;
    Event(int l=0, int r=0, int val=0): l(l), r(r), val(val) {}
};

int main(){
    int n;
    cin >> n;
    vector<Rect> rects;
    const int M = 1e9;
    rep(i,n){
        int l, r;
        cin >> l >> r;
        rects.eb(0,l,l+1,r);
        rects.eb(l+1,r,r+1,M+1);
    }

    CC<int> xs, ys;
    for(auto [lx,rx,ly,ry] : rects){
        xs.add(lx); xs.add(rx);
        ys.add(ly); ys.add(ry);
    }
    vector<vector<Event>> events(xs.size());
    for(auto&& [lx,rx,ly,ry] : rects){
        lx = xs(lx); rx = xs(rx);
        ly = ys(ly); ry = ys(ry);
        events[lx].eb(ly,ry,1);
        events[rx].eb(ly,ry,-1);
    }

    lazy_segtree<S,op,e,int,mapping,composition,id> t(ys.size());
    rep(i,ys.size()) t.set(i,S(0,i));

    int ans = 0, ansl=0, ansr=1;
    rep(xi,xs.size()){
        for(auto [l,r,val] : events[xi]){
            t.apply(l,r,val);
        }
        S s = t.all_prod();
        if(ans<s.val){
            ans = s.val;
            ansl = xs[xi];
            ansr = ys[s.y];
        }
    }

    cout << ansl << " " << ansr << endl;
}
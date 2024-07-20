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

struct S{
    ll zero, one, val;
    S(ll zero=0, ll one=0, ll val=0): zero(zero), one(one), val(val) {}
};

S op(S x, S y){
    return S(x.zero+y.zero, x.one+y.one, x.val+y.val + x.one*y.zero);
}

S e(){return S(0,0,0);}

using F = bool;

S mapping(F f, S s){
    if(f) return S(s.one, s.zero, s.one*s.zero - s.val);
    else return s;
}

F composition(F g, F f){
    if(g) f = !f;
    return f;
}

F id(){return false;}


int main(){
    int n, q;
    cin >> n >> q;
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(n);
    rep(i,n){
        int a;
        cin >> a;
        if(a) seg.set(i,S(0,1,0));
        else seg.set(i,S(1,0,0));
    }

    rep(qi,q){
        int t, l, r;
        cin >> t >> l >> r;
        l--; 
        if(t==1){
            seg.apply(l,r,true);
        }
        if(t==2){
            S res = seg.prod(l,r);
            cout << res.val << endl;
        }
    }
}
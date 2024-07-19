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
    mint val;
    ll siz;
    S(mint val=0, ll siz=0): val(val), siz(siz) {}
};

S op(S x, S y){return S(x.val+y.val, x.siz+y.siz);}

S e(){return S(0,0);}

struct F{
    mint b, c;
    F(mint b=0, mint c=0): b(b), c(c) {}
};

S mapping(F f, S s){
    return S(f.b*s.val+f.c*s.siz, s.siz);
}

F composition(F g, F f){
    return F(g.b*f.b, g.b*f.c+g.c);
}

F id(){return F(1,0);}

int main(){
    int n, q;
    cin >> n >> q;
    lazy_segtree<S,op,e,F,mapping,composition,id> t(n);
    rep(i,n){
        ll x;
        cin >> x;
        t.set(i,S(x,1));
    }

    vector<mint> ans;
    rep(qi,q){
        int type;
        cin >> type;
        if(type==0){
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c;
            t.apply(l,r,F(b,c));
        }
        if(type==1){
            int l, r;
            cin >> l >> r;
            S res = t.prod(l,r);
            ans.pb(res.val);
        }
    }

    for(mint res : ans) cout << res.val() << endl;
}
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
using mint = modint998244353;
//using mint = modint1000000007;
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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct S{
    mint len, a, b, ab;
};

struct F{
    mint a_add, b_add;
};

S op(S x, S y){
    return S{
        x.len + y.len,
        x.a + y.a,
        x.b + y.b,
        x.ab + y.ab
    };
}

S e(){return S{mint(0),mint(0),mint(0),mint(0)};}

S mapping(F f, S x){
    return S{
        x.len,
        x.a + f.a_add*x.len,
        x.b + f.b_add*x.len,
        x.ab + f.b_add*x.a + f.a_add*x.b + f.a_add*f.b_add*x.len
    };
}

F composition(F f, F g){return F{f.a_add+g.a_add, f.b_add+g.b_add};}
F id(){return F{mint(0), mint(0)};}


int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    lazy_segtree<S,op,e,F,mapping,composition,id> t(n);
    rep(i,n){
        t.set(i,S{mint(1),mint(a[i]),mint(b[i]),mint(a[i])*mint(b[i])});
    }

    rep(qi,q){
        int type, l, r;
        cin >> type >> l >> r;
        if(type==1){
            int x;
            cin >> x;
            t.apply(l-1,r,F{mint(x),mint(0)});
        }
        if(type==2){
            int x;
            cin >> x;
            t.apply(l-1,r,F{mint(0),mint(x)});
        }
        if(type==3){
            cout << t.prod(l-1,r).ab.val() << endl;
        }
    }
}
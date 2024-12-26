#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using db = double; 
using ull = unsigned long long;
using ld = long double; 
using bl = bool;
const int inf = 1001001001; 
const ll INF = 5e18;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>; using vvvvi = vv<vvi>;
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vdb = vc<db>; using vvdb = vv<db>; using vvvdb = vv<vdb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using vs = vc<string>; using vvs = vv<string>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define repp(i,n) for(ll i=1; i<=(n); i++)
#define drep(i,n) for(ll i=(n)-1; i>=0; i--)
#define nfor(i,s,n) for(ll i=s; i<n; i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
template<typename T> void chmax(T& x, T y) {x = max(x, y);}
template<typename T> void chmin(T& x, T y) {x = min(x, y);}
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define YN {cout << "Yes" << endl;}else{cout << "No" << endl;}
#define TKAK {cout << "Takahashi" << endl;}else{cout << "Aoki" << endl;}
#define next_p(v) next_permutation(v.begin(),v.end())
bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define fi first
#define se second
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint; //mint::set_mod(m);で定義できる
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
//using P = pair<db, int>;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct S{
    int l0, l1, r0, r1, siz, max0, max1;
};
using F = int;
S op(S a, S b){
    S res;
    res.siz = a.siz + b.siz;
    if(a.siz==a.l1){
        res.l1 = a.l1 + b.l1;
        res.l0 = 0;
        res.r0 = b.r0;
        if(b.l1==b.siz) res.r1 = res.l1;
        else res.r1 = b.r1; 
    }
    else if(a.siz==a.l0){
        res.l0 = a.l0 + b.l0;
        res.l1 = 0;
        res.r1 = b.r1;
        if(b.l0==b.siz) res.r0 = res.l0;
        else res.r0 = b.r0;
    }
    else{
        res.l0 = a.l0;
        res.l1 = a.l1;
        if(b.l0==b.siz){
            res.r0 = a.r0 + b.siz;
            res.r1 = 0;
        }
        else if(b.l1==b.siz){
            res.r0 = 0;
            res.r1 = a.r1 + b.siz;
        }
        else{
            res.r0 = b.r0;
            res.r1 = b.r1;
        }
    }

    res.max0 = max({a.max0, b.max0, a.r0+b.l0, a.l0, b.r0});
    res.max1 = max({a.max1, b.max1, a.r1+b.l1, a.l1, b.r1}); 
    return res;
}
S e(){return S{0,0,0,0,0,0,0};}
S mapping(F f, S x){
    if(f==0) return x;
    swap(x.l0,x.l1);
    swap(x.r0,x.r1);
    swap(x.max0,x.max1);
    return x;
}
F composition(F f, F g){return (f+g)%2;}
F id(){return 0;}

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;

    lazy_segtree<S,op,e,F,mapping,composition,id> t(n);
    rep(i,n){
        int l0, l1, r0, r1, siz, max0, max1;
        if(s[i]=='0') t.set(i,S{1,0,1,0,1,1,0});
        if(s[i]=='1') t.set(i,S{0,1,0,1,1,0,1});
    }

    rep(qi,q){
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        if(c==1){
            t.apply(l,r,1);
        }
        if(c==2){
            S ans = t.prod(l,r);
            cout << ans.max1 << endl;
        }
    }
}
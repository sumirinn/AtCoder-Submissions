#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using ll = long long;
const int inf = 1001001001; 
const ll INF = 2e18;
using db = double; 
using ull = unsigned long long;
using ld = long double; 
using bl = bool;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint; //mint::set_mod(m);で定義できる
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>; using vvvvi = vv<vvi>;
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vdb = vc<db>; using vvdb = vv<db>; using vvvdb = vv<vdb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using vs = vc<string>; using vvs = vv<string>;
using ar2 = array<ll, 2>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define repp(i,n) for(ll i=1; i<=(n); i++)
#define drep(i,n) for(ll i=(n)-1; i>=0; i--)
#define nfor(i,s,n) for(ll i=s; i<n; i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
void chmax(ll& x, ll y) {x = max(x, y);}
void chmin(ll& x, ll y) {x = min(x, y);}
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define YN {cout << "Yes" << endl;}else{cout << "No" << endl;}
#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());
#define next_p(v) next_permutation(v.begin(),v.end())
bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
#define vvl_kaiten(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//時計回りに90°回転
//#define vvl_kaiten(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//反時計周りに90°回転
#define vs_kaiten(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//文字列版 時計回りに90°回転
//#define vs_kaiten(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//文字列版　反時計周りに90°回転
#define vvl_tenti(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][i]=v[i][j];swap(nx,v);}
#define vs_tenti(v) {ll n = size(v); vs nx(n, string(n,'.')); rep(i, n)rep(j, n)nx[j][i] = v[i][j]; swap(nx, v);}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define fi first
#define se second
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
template<class T>istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }
using P = pair<db, int>;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    ll n;
    int m;
    cin >> n >> m;
    vector<pll> a(m);
    rep(i,m) cin >> a[i].fi;
    rep(i,m) cin >> a[i].se;
    sort(nall(a));

    ll ns=0, pos=0;
    rep(i,m){
        if(ns<a[i].fi-1){
            cout << -1 << endl;
            return 0;
        }
        ns += a[i].se;
        pos += a[i].se*a[i].fi;
    }
    if(ns!=n){
        cout << -1 << endl;
        return 0;
    }

    cout << c2(n+1) - pos << endl;
}
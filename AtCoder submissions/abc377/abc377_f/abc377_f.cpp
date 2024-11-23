#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using db = double; 
using ull = unsigned long long;
using ld = long double; 
using bl = bool;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint; //mint::set_mod(m);で定義できる
const int inf = 1001001001; 
const ll INF = 2e18;
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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
//using P = pair<db, int>;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    ll n;
    int m;
    cin >> n >> m;
    set<int> X, Y, S, D;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        X.insert(a);
        Y.insert(b);
        S.insert(a+b);
        D.insert(a-b);
    }

    ll ans = n*n;
    for(int x : X) ans -= n;
    for(int y : Y) ans -= n;
    for(int s : S) ans -= n - abs(s-(n-1));
    for(int d : D) ans -= n - abs(d);

    unordered_map<ll,int> cnt;
    auto add = [&](int x, int y){
        if(out_grid(x,y,n,n)) return;
        cnt[(ll)x<<30|y]++;
    };
    for(int x : X)for(int y : Y) add(x,y);
    for(int x : X)for(int s : S) add(x,s-x);
    for(int x : X)for(int d : D) add(x,x-d);
    for(int y : Y)for(int s : S) add(s-y,y);
    for(int y : Y)for(int d : D) add(y+d,y);
    for(int s : S)for(int d : D){
        if((s+d)%2) continue;
        add((s+d)/2,(s-d)/2);
    }

    for(auto[p,num] : cnt){
        if(num==1) ans += 1;
        if(num==3) ans += 2;
        if(num==6) ans += 3;
    }

    cout << ans << endl;
}
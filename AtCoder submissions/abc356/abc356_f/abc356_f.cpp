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


// Coordinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
struct CC {
    bool initialized;
    //座標圧縮が初期化されているかどうかを示すbool型変数
    vector<T> xs;
    CC(): initialized(false) {}
    void add(T x) { xs.push_back(x); }
    void init() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        //重複要素の削除
        initialized = true;
    }
    //xs.(a[i])とかで圧縮後の座標が返るようにしている
    int operator()(T x) {
        if (!initialized) init();//初期化されていない場合は初期化
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
    }
    //xs[i]でi番目の値が返るようにしている
    T operator[](int i) {
        if (!initialized) init();
        return xs[i];
    }
    int size() {
        if (!initialized) init();
        return xs.size();
    }
};


int main(){
    int q;
    ll k;
    cin >> q >> k;
    vc<pil>qs;
    CC<ll> cc;
    rep(qi,q){
        int type;
        ll x;
        cin >> type >> x;
        qs.eb(type,x);
        cc.add(x);
    }

    cc.add(-INF);
    cc.add(INF);
    set<ll> s;
    s.insert(-INF);
    s.insert(INF);
    set<ll> gap;
    gap.insert(-INF);
    gap.insert(INF);
    fenwick_tree<int> d(cc.size());

    for(auto [type,x] : qs){
        if(type==1){
            if(s.count(x)){
                auto it = s.find(x);
                s.erase(it--);
                gap.erase(x);
                ll l = *it;
                it++;
                ll r = *it;
                if(r-l>k) gap.insert(l);
                d.add(cc(x),-1);
            }
            else{
                auto it = s.lower_bound(x);
                ll r = *it;
                it--;
                ll l = *it;
                gap.erase(l);
                s.insert(x);
                if(x-l>k) gap.insert(l);
                if(r-x>k) gap.insert(x); 
                d.add(cc(x),1);
            }
        }
        if(type==2){
            auto it = gap.lower_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            int ans = d.sum(cc(l)+1,cc(r)+1);
            cout << ans << endl;
        }
    }
}
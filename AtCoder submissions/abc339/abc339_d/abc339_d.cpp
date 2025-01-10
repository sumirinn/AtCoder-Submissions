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


int main(){
    int n;
    cin >> n;
    vc<string> s(n);
    rep(i,n) cin >> s[i];
    int st = 0;
    rep(i,n)rep(j,n)if(s[i][j]=='P'){
        st *= n; st += j;
        st *= n; st += i;
    }

    int n4 = n*n*n*n;
    using P = pair<pii,pii>;
    auto p2i =[&](int pos)->P{
        P res;
        res.fi.fi = pos%n; pos /= n;
        res.fi.se = pos%n; pos /= n;
        res.se.fi = pos%n; pos /= n;
        res.se.se = pos%n;
        return res;
    };
    auto i2p =[&](int i1, int j1, int i2, int j2)->int{
        int res = 0;
        res += j2; res *= n;
        res += i2; res *= n;
        res += j1; res *= n;
        res += i1;
        return res;
    };

    vvi to(n4);
    rep(pos,n4){
        P now = p2i(pos);
        int i1 = now.fi.fi;
        int j1 = now.fi.se;
        int i2 = now.se.fi;
        int j2 = now.se.se;
        if(i1==i2 && j1==j2) continue;
        if(s[i1][j1]=='#') continue;
        if(s[i2][j2]=='#') continue;
        rep(v,4){
            int ni1 = i1 + di[v];
            int nj1 = j1 + dj[v];
            int ni2 = i2 + di[v];
            int nj2 = j2 + dj[v];
            bool c1 = false;
            bool c2 = false;
            if(out_grid(ni1,nj1,n,n)){
                c1 = true;
                ni1 -= di[v];
                nj1 -= dj[v];
            }
            if(out_grid(ni2,nj2,n,n)){
                c2 = true;
                ni2 -= di[v];
                nj2 -= dj[v];
            }
            if(s[ni1][nj1]=='#' && c1==false){
                c1 = true;
                ni1 -= di[v];
                nj1 -= dj[v];
            }
            if(s[ni2][nj2]=='#' && c2==false){
                c2 = true;
                ni2 -= di[v];
                nj2 -= dj[v];
            }
            if(c1 && c2) continue;
            int nex = i2p(ni1,nj1,ni2,nj2);
            to[pos].pb(nex);
        }
    }

    queue<int> q;
    vi dist(n4,inf);
    q.push(st);
    dist[st] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int nex : to[now]){
            if(dist[nex]<=dist[now]+1) continue;
            dist[nex] = dist[now] + 1;
            q.push(nex);
        }
    }

    int ans = inf;
    rep(pos,n4){
        P now = p2i(pos);
        if(now.fi.fi==now.se.fi && now.fi.se==now.se.se){
            chmin(ans,dist[pos]);
        }
    }
    if(ans==inf) ans = -1;
    cout << ans << endl;
}
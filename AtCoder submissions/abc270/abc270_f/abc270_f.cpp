#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
//#define int long long
//typedef long long int;
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる。
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
//auto nex = calc_next で取得すると楽。
vector<vector<int> > calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int> > res(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, pii>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


int main(){
    int n, m;
    cin >> n >> m;
    //n:空港、n+1港
    vector<P> es;
    rep(i,n){
        ll x;
        cin >> x;
        es.emplace_back(x,pii(i,n));
    }
    rep(i,n){
        ll x;
        cin >> x;
        es.emplace_back(x,pii(i,n+1));
    }
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(c,pii(a,b));
    }
    sort(es.begin(),es.end());
    ll ans = INF;
    int N = n*2+m;

    dsu uf1(n);
    ll cnt1 = 0;
    int siz = 1;
    rep(i,N){
        auto [w,e] = es[i];
        auto [u,v] = e;
        if(u>=n||v>=n) continue;
        if(uf1.same(u,v)) continue;
        cnt1 += w;
        uf1.merge(u,v);
        siz++;
    }
    if(siz!=n) cnt1 = INF;
    ans = min(ans,cnt1);

    dsu uf2(n+2);
    ll cnt2 = 0;
    siz = 1;
    rep(i,N){
        auto [w,e] = es[i];
        auto [u,v] = e;
        if(u==n+1||v==n+1) continue;
        if(uf2.same(u,v)) continue;
        cnt2 += w;
        uf2.merge(u,v);
        siz++;
    }
    if(siz!=n+1) cnt2 = INF;
    ans = min(ans,cnt2);

    dsu uf3(n+2);
    ll cnt3 = 0;
    siz = 1;
    rep(i,N){
        auto [w,e] = es[i];
        auto [u,v] = e;
        if(u==n||v==n) continue;
        if(uf3.same(u,v)) continue;
        cnt3 += w;
        uf3.merge(u,v);
        siz++;
    }
    if(siz!=n+1) cnt3 = INF;
    ans = min(ans,cnt3);

    dsu uf4(n+2);
    ll cnt4 = 0;
    siz = 1;
    rep(i,N){
        auto [w,e] = es[i];
        auto [u,v] = e;
        if(uf4.same(u,v)) continue;
        cnt4 += w;
        uf4.merge(u,v);
        siz++;
    }
    if(siz!=n+2) cnt4 = INF;
    ans = min(ans,cnt4);

    cout << ans << endl;
}
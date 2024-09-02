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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


pii op(pii a, pii b){return max(a,b);}
pii e(){return pii(0,-1);}

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<pii> coins;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        coins.eb(r,c);
    }
    sort(coins.begin(),coins.end());

    const int mx = 200005;
    segtree<pii,op,e> t(mx);
    vector<int> pre(n);
    rep(i,n){
        int y = coins[i].se;
        auto [lis,idx] = t.prod(0,y+1);
        pre[i] = idx;
        t.set(y,pii(lis+1,i));
    }

    string ans = "";
    int r=h, c=w;
    auto mv = [&](pii p){
        auto [nr,nc] = p;
        while(r>nr) r--, ans += 'D';
        while(c>nc) c--, ans += 'R';
    };

    auto [lis,i] = t.all_prod();
    while(i!=-1){
        mv(coins[i]);
        i = pre[i];
    }
    mv(pii(1,1));
    reverse(ans.begin(),ans.end());
    cout << lis << endl;
    cout << ans << endl;
}
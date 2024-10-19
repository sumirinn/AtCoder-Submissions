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
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> to(n);
    rep(i,q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        to[x].pb(y);
    }

    vector<int> blocked(n,0);
    vector<int> res;
    const int m = 1e4;
    vector<vector<vector<int>>> ans(m);
    bool fin = false;
    auto dfs =[&](auto dfs, int now, int sum)->void{
        if(fin) return;
        if(now==n){
            ans[sum].pb(res);
            if(ans[sum].size()==2) fin = true;
            return;
        }
        dfs(dfs,now+1,sum);
        if(blocked[now]==false){
            for(int nex: to[now]) blocked[nex]++;
            res.pb(now);
            dfs(dfs,now+1,sum+a[now]);
            for(int nex : to[now]) blocked[nex]--;
            res.pop_back();
        }
    };
    dfs(dfs,0,0);
    rep(i,m){
        if(ans[i].size()==2){
            rep(ri,2){
                cout << ans[i][ri].size() << endl;
                for(int e : ans[i][ri]) cout << e + 1 << " ";
                cout << endl;
            }
        }
    }
}
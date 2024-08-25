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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, k;
    cin >> n >> k;
    vector<set<int>> to(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].insert(v);
        to[v].insert(u);
    }
    vector<bool> d(n,false);
    rep(i,k){
        int v;
        cin >> v;
        v--;
        d[v] = true;
    }

    vector<bool> g(n,true);
    queue<int> q;
    rep(i,n) if(to[i].size()==1 && d[i]==false) q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(to[v].size()!=1) continue;
        if(d[v]) continue;
        g[v] = false;
        for(int u : to[v]){
            to[u].erase(v);
            q.push(u);
        }
    }

    int ans = 0;
    rep(i,n) if(g[i]) ans++;
    cout << ans << endl;
}
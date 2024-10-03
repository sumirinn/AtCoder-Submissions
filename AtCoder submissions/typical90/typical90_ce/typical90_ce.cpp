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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        to[v].pb(u);
    }

    int b = int(sqrt(2*m));
    vector<int> l;
    rep(i,n)if(to[i].size()>=b) l.pb(i);

    int siz = l.size();
    vector<vector<bool>> link(n,vector<bool>(siz,false));
    rep(i,siz){
        for(int j : to[l[i]]){
            link[j][i] = true;
        }
        link[l[i]][i] = true;
    }
    vector<int> upd(n,-1);
    vector<int> lupd(siz,-1);

    int q;
    cin >> q;
    vector<int> y(q);
    rep(i,q){
        int x;
        cin >> x >> y[i];
        x--;

        int last = upd[x];
        rep(j,siz)if(link[x][j]) last = max(last,lupd[j]);
        if(last==-1) cout << 1 << endl;
        else cout << y[last] << endl;

        if(to[x].size()<b){
            upd[x] = i;
            for(int j : to[x]) upd[j] = i;
        }
        else{
            int ptr = find(l.begin(),l.end(),x) - l.begin();
            lupd[ptr] = i;
        }
    }
}
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
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    int n2 = 1<<n;
    vector<int> mem(n2,inf);
    auto dfs =[&](auto dfs, int now)->bool{
        if(mem[now]!=inf) return mem[now];
        bool res = false;
        rep(i,n)rep(j,n){
            if(i==j) continue;
            if((1&(now>>i))==0 || (1&(now>>j))==0) continue;
            if(a[i]==a[j] || b[i]==b[j]){
                int nex = now;
                nex -= 1<<i;
                nex -= 1<<j;
                if(dfs(dfs,nex)==false) res = true; 
            } 
        }
        return mem[now] = res;
    };

    int st = 0;
    rep(i,n) st |= 1<<i;
    dfs(dfs,st);
    if(mem[st]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl; 
}
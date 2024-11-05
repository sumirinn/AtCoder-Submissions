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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> S(h);
    rep(i,h) cin >> S[i];

    int ans = 0;
    rep(si,h)rep(sj,w){
        if(S[si][sj]=='#') continue;
        vector<vector<bool>> used(h,vector<bool>(w,false));
        used[si][sj] = true;
        auto dfs =[&](auto dfs, int ni, int nj, int cnt)->void{
            if(cnt==k){
                ans++;
                return;
            }
            rep(v,4){
                int fi=ni+di[v], fj=nj+dj[v];
                if(fi<0||fj<0||fi>=h||fj>=w) continue;
                if(used[fi][fj]) continue;
                if(S[fi][fj]=='#') continue;

                used[fi][fj] = true;
                dfs(dfs,fi,fj,cnt+1);
                used[fi][fj] = false;
            }
        };
        dfs(dfs,si,sj,0);
    }
    cout << ans << endl;
}
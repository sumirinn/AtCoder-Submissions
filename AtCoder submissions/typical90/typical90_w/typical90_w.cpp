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


const int m = 1<<18;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];


    vector<vector<bool>> used(h+3,vector<bool>(w,false));
    auto f =[&](int i, int j)->bool{
        rep(v,8){
            int ni = i + dx[v];
            int nj = j + dy[v];
            if(ni<0||nj<0||nj>=w) continue;
            if(used[ni][nj]) return false;
        }
        return true;
    };


    vector<int> cnt(w,0);
    vector<vector<int>> state(w,vector<int>(m,0));
    using P = pair<int, bool>;
    vector<map<int,P>> mp(w);

    auto dfs = [&](auto dfs, int pos, int dep, int str)->void{
        int ni = pos/w;
        int nj = pos%w;

        if(dep==w+1){
            int idx = cnt[nj];
            state[nj][idx] = str;
            mp[nj][str] = P(idx,f(ni,nj));
            cnt[nj]++;
            return;
        }

        dfs(dfs,pos+1,dep+1,str);
        if(f(ni,nj)){
            used[ni][nj] = true;
            dfs(dfs, pos+1, dep+1, str+(1<<dep));
            used[ni][nj] = false;
        }
    };
    rep(j,w) dfs(dfs,j,0,0);


    vector<vector<int>> nex0(w,vector<int>(m,0));
    vector<vector<int>> nex1(w,vector<int>(m,0));
    rep(j,w){
        rep(k,cnt[j]){
            int t = state[j][k];
            int t0 = (t>>1);
            int t1 = (t>>1) + (1<<w);

            nex0[j][k] = mp[(j+1)%w][t0].fi;
            if(mp[j][t].se) nex1[j][k] = mp[(j+1)%w][t1].fi;
            else nex1[j][k] = -1;
        }
    }


    vector<vector<vector<mint>>> dp(h+1,vector<vector<mint>>(w+1,vector<mint>(m,0)));
    dp[0][0][0] = 1;
    rep(i,h)rep(j,w){
        int n1 = i;
        int n2 = j + 1;
        if(n2==w){
            n1++;
            n2=0;
        }

        rep(k,cnt[j]){
            if(dp[i][j][k]==0) continue;
            dp[n1][n2][nex0[j][k]] += dp[i][j][k];
            if(nex1[j][k]!=-1 && c[i][j]=='.'){
                dp[n1][n2][nex1[j][k]] += dp[i][j][k];
            }
        }
    }

    mint ans = 0;
    rep(k,cnt[0]) ans += dp[h][0][k];
    cout << ans.val() << endl;
}
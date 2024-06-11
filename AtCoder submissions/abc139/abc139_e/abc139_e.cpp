#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


const int mx = 1005;
const int mv = mx*(mx-1)/2;
vector<int> to[mv];
int id[mx][mx];
int toid(int i, int j){
    if(i>j) swap(i,j);
    return id[i][j];
}

bool visited[mv];
bool calculated[mv];
int dp[mv];
int dfs(int v){
    if(visited[v]){
        if(!calculated[v]) return -1;
        return dp[v];
    }
    visited[v] = true;
    dp[v] = 1;
    for(int u : to[v]){
        int res = dfs(u);
        if(res==-1) return -1;
        dp[v] = max(dp[v],res+1);
    }
    calculated[v] = true;
    return dp[v];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n-1));
    rep(i,n)rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }

    int V = 0;
    rep(i,n)rep(j,n) if(i<j) id[i][j] = V++;

    rep(i,n){
        rep(j,n-1){
            a[i][j] = toid(i,a[i][j]);
        }
        rep(j,n-2){
            to[a[i][j+1]].pb(a[i][j]);
        }
    }

    int ans = 0;
    rep(i,V){
        int res = dfs(i);
        if(res==-1){
            cout << -1 << endl;
            return 0;
        }
        chmax(ans,res);
    }
    cout << ans << endl;
}
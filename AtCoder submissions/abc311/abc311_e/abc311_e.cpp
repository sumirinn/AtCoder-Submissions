#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> c(h+1, vector<int>(w+1, 0));
    rep(i, n){
        int a, b;
        cin >> a >> b;
        c[a][b] = 1;
    }
    rep(i, h+1)rep(j, w) c[i][j+1] += c[i][j];
    rep(j, w+1)rep(i, h) c[i+1][j] += c[i][j];


    auto f = [&](int s, int t, int l) -> bool {
        int u = s+l, v = t+l;
        if(h<u || w<v) return false;
        return c[u][v] - c[s-1][v] - c[u][t-1] + c[s-1][t-1]==0;
    };

    ll ans = 0;
    int m = min(h, w);
    repp(i, h)repp(j, w){
        if(!f(i, j, 0)) continue;

        int l = 0, r = m+1;
        while(l<r-1){
            int M = (l+r) / 2;
            if(f(i, j, M)) l = M;
            else r = M;
        }
        ans += r;
    }

    cout << ans << endl;
}
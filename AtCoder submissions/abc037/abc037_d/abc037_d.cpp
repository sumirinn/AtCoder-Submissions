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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


ll dp[1000009];

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];

    int n = h*w;
    vector<vector<int>> to(n);
    vector<int> deg(n);
    rep(i, h)rep(j, w){
        rep(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(a[i][j]<a[ni][nj]){
                to[w*i+j].push_back(w*ni+nj);
                deg[w*ni+nj]++;
            }
        }
    }
    
    queue<int> q;
    rep(i, n) if(deg[i]==0) q.push(i);
    rep(i, n) dp[i] = ll(1);

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : to[v]){
            deg[u]--;
            dp[u] += dp[v];
            dp[u] %= ll(1e9) + ll(7);
            if(deg[u]==0){
                q.push(u);
            }
        }
    }

    ll ans = 0;
    rep(i, n){
        dp[i] %= ll(1e9) + ll(7);
        ans += dp[i];
        ans %= ll(1e9) + ll(7);
    }

    cout << ans << endl;
}
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
using MP = map<int, vector<int>>;
using mint = modint998244353;
using P = pair<int, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int main(){
    int n; cin >> n;
    vector<vector<int>> to(n);
    rep(i,n-1){
        int u, v; cin >> u >> v; u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    vector<int> dist(n);
    queue<int> q;
    auto bfs = [&](int st) -> void{
        dist = vector<int>(n, inf);
        dist[st] = 0;
        q.push(st);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int u : to[v]){
                if(dist[u]!=inf) continue;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    };

    bfs(0);
    int st=-1, l=-1;
    rep(i,n)if(dist[i]>l){ st = i; l = dist[i]; }

    bfs(st);
    int ans = 0;
    rep(i,n) ans = max(ans, dist[i]);
    cout << ans + 1 << endl;
}
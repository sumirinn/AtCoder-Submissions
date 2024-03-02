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
using P = pair<mint, ll>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int & x, int y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
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
    int n, m, k;
    cin >> n >> m >> k;
    int s = n*2;
    vector<vector<int>> to(s);
    rep(mi, m){
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        if(a==1){
            to[u].push_back(v);
            to[v].push_back(u);
        }
        if(a==0){
            to[u+n].push_back(v+n);
            to[v+n].push_back(u+n);
        }
    }
    rep(ki, k){
        int t;
        cin >> t;
        t--;
        to[t].push_back(t+n);
        to[t+n].push_back(t);
    }

    vector<int> dist(s, inf);
    dist[0] = 0;
    deque<int> q;
    q.emplace_back(0);
    while(!q.empty()){
        int v = q.front(); q.pop_front();
        for(int u : to[v]){
            if(dist[u]!=inf) continue;
            if(v%n==u%n){
                dist[u] = dist[v];
                q.emplace_front(u);
            }else{
                dist[u] = dist[v] + 1;
                q.emplace_back(u);
            }
        }
    }

    int ans = min(dist[n-1], dist[s-1]);
    if(ans==inf) ans = -1;
    cout << ans << endl;
}
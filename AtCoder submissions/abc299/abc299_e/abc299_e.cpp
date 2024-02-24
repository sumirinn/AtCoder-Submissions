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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> p(k), D(k);
    rep(i, k){
        cin >> p[i] >> D[i];
        p[i]--;
    }

    vector<vector<int>> g(n);
    auto bfs = [&](int sv){
        vector<int> d(n, inf);
        queue<int> q;
        q.push(sv);
        d[sv] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int u : to[v]){
                if(d[u]!=inf) continue;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
        return d;
    };
    rep(i, n) g[i] = bfs(i);

    string ans(n, '1');
    rep(i, k){
        rep(v, n){
            if(g[p[i]][v]<D[i]) ans[v] = '0';
        }
    }

    rep(i, k){
        int now = inf;
        rep(v, n) if(ans[v]=='1'){
            now = min(now, g[p[i]][v]);
        }
        if(now!=D[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;
}
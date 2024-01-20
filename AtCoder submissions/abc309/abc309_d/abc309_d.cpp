#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
int inf = 1001001001;
//97~122(a~z)

int main(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int n = n1 + n2;
    vector<vector<int>> to(n);
    repp(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> d1, d2;
    auto bfs = [&] (int sv) {
        vector<int> dist(n, inf);
        dist[sv] = 0;
        queue<int> q;
        q.push(sv);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u : to[v]){
                if(dist[u]!=inf) continue;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
        return dist;
    };

    d1 = bfs(0);
    d2 = bfs(n-1);

    int D1 = 0, D2 = 0;
    repp(i, n1) D1 = max(D1, d1[i]);
    repp(i, n2) D2 = max(D2, d2[n1+i]);
    cout << D1 + D2 + 1 << endl;
}
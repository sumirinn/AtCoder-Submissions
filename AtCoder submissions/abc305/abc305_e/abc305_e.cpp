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
const int inf = 1001001001;
//97~122(a~z)

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> to(n);
    repp(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> d(n, -1);
    priority_queue<P> q;
    repp(i, k){
        int p, h;
        cin >> p >> h;
        p--;
        d[p] = h;
        q.emplace(h, p);
    }

    while(!q.empty()){
        auto [h, v] = q.top(); q.pop();
        if(d[v]>h) continue;
        for(int u : to[v]){
            if(d[u]>=h-1) continue;
            d[u] = h - 1;
            q.emplace(h-1, u);
        }
    }
    
    vector<int> ans;
    repp(i, n)if(d[i]>=0) ans.push_back(i+1);
    cout << ans.size() << endl;
    repp(i, ans.size()) cout << ans[i] << " ";
    cout << endl;

}
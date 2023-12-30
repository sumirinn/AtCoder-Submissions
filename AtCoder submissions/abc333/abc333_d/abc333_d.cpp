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

int main(){
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    int ans = n;
    for(int v : to[0]){
        auto f = [&](auto f, int v, int p=-1) -> int {
            int res = 1;
            for(int u : to[v]){
                if(u==p) continue;
                res += f(f, u, v);
            }
            return res;
        };
        int now = n - f(f, v, 0);
        ans = min(ans, now);
    }
    cout << ans << endl;
}
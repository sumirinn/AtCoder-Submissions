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

using vvi = vector<vector<int>>;

int main(){
    int h, w;
    cin >> h >> w;
    vvi a(h, vector<int>(w));
    vvi b(h, vector<int>(w));
    repp(i, h)repp(j, w) cin >> a[i][j];
    repp(i, h)repp(j, w) cin >> b[i][j];

    queue<vvi> q;
    map<vvi, int> dist;

    auto push = [&](vvi& s, int d){
        if(dist.count(s)==1) return;
        dist[s] = d;
        q.push(s);
    };

    push(a, 0);

    while(!q.empty()){
        vvi s = q.front(); q.pop();
        int d = dist[s];
        repp(i, h-1){
            vvi ns = s;
            swap(ns[i], ns[i+1]);
            push(ns, d+1);
        }
        repp(j, w-1){
            vvi ns = s;
            repp(i, h) swap(ns[i][j], ns[i][j+1]);
            push(ns, d+1);
        }
    }

    if(dist.count(b)==1) cout << dist[b] << endl;
    else cout << -1 << endl;
}
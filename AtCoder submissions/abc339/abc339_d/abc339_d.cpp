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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<P> ps;
    rep(i, n)rep(j, n){
        if(s[i][j]=='P') ps.emplace_back(i, j);
    }

    auto to_i = [&](vector<P> ps) {
        int res = 0;
        res = res*n + ps[0].first;
        res = res*n + ps[0].second;
        res = res*n + ps[1].first;
        res = res*n + ps[1].second;
        return res;
    };

    auto to_ps = [&](int id) {
        vector<P> p(2);
        p[1].second = id%n; id /= n;
        p[1].first = id%n; id /= n;
        p[0].second = id%n; id /= n;
        p[0].first = id%n; id /= n;
        return p;
    };

    int m = n*n*n*n;
    vector<int> dist(m, inf);
    queue<int> q;
    
    int sid = to_i(ps);
    dist[sid] = 0;
    q.push(sid);

    while(!q.empty()){
        int id = q.front(); q.pop();
        int d = dist[id];
        vector<P> ps = to_ps(id);
        rep(v, 4){
            vector<P> nps;
            for(auto [i, j] : ps){
                int ni = i + di[v], nj = j + dj[v];
                if(ni<0 || nj<0 || n<=ni || n<=nj || s[ni][nj]=='#'){
                    ni = i; nj = j; //移動しない場合
                }
                nps.emplace_back(ni, nj); //ベクトル2個入る
            }
            int nid = to_i(nps);
            if(dist[nid]!=inf) continue;
            dist[nid] = d + 1;
            q.push(nid);
        }
    }

    int ans = inf;
    rep(id, m){
        vector<P> ps = to_ps(id);
        int d = dist[id];
        if(ps[0]==ps[1]) ans = min(ans, d);
    }
    if(ans==inf) cout << -1 << endl;
    else cout << ans << endl;
}
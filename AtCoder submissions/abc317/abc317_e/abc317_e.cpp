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
//97~122(a~z)

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    repp(i, h) cin >> s[i];
    int si, sj, gi, gj;
    repp(i, h)repp(j, w){
        if(s[i][j]=='S') si = i, sj = j, s[i][j] = '.';
        if(s[i][j]=='G') gi = i, gj = j, s[i][j] = '.';
    }

    vector<vector<bool>> ng(h, vector<bool>(w));
    repp(i, h)repp(j, w){
        int v = -1;
        if(s[i][j] == '^') v = 0;
        if(s[i][j] == '<') v = 1;
        if(s[i][j] == 'v') v = 2;
        if(s[i][j] == '>') v = 3;
        if(s[i][j] == '#') ng[i][j] = true;
        if(v==-1) continue;
        int ni = i, nj = j;
        while(1){
            ng[ni][nj] = true;
            ni += di[v];
            nj += dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>= w) break;
            if(s[ni][nj]!='.') break;
        }
    }

    const int inf = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    queue<P> q;
    q.emplace(si, sj); 
    dist[si][sj] = 0;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        repp(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>= w) continue;
            if(ng[ni][nj]) continue;
            if(dist[ni][nj]!=inf) continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.emplace(ni, nj);
        }
    }
    int ans = dist[gi][gj];
    if(ans==inf) ans = -1;
    cout << ans << endl;
}
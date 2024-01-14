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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    repp(i, n) cin >> s[i];

    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<bool>> passed(n, vector<bool>(m));
    queue<P> q;
    q.emplace(1, 1);
    passed[1][1] = true;
    visited[1][1] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        repp(v,4){
            int ni = i, nj = j;
            while(s[ni][nj]=='.'){
                passed[ni][nj] = true;
                ni += di[v];
                nj += dj[v];
            }
            ni -= di[v];
            nj -= dj[v];
            if(visited[ni][nj]) continue;
            visited[ni][nj] = true;
            q.emplace(ni, nj);
        }
    }

    int ans = 0;
    repp(i, n)repp(j, m) if(passed[i][j]) ans++;
    cout << ans << endl;
}


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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    repp(i, h) cin >> s[i];

    queue<P> q;
    q.emplace(0, 0); 
    if(s[0][0]!='s' && s[0][0]!='n' && s[0][0]!='u' && s[0][0]!='k' && s[0][0]!='e'){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<bool>> visited(h, vector<bool>(w));
    visited[0][0] = true;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        char b = 'A';
        if(s[i][j]=='s') b = 'n';
        if(s[i][j]=='n') b = 'u';
        if(s[i][j]=='u') b = 'k';
        if(s[i][j]=='k') b = 'e';
        if(s[i][j]=='e') b = 's';
        if(b=='A') continue;
        repp(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>= w) continue;
            if(visited[ni][nj]) continue;
            if(s[ni][nj]==b){
                visited[ni][nj] = true;
                q.emplace(ni, nj);
            }
        }
    }
    if(visited[h-1][w-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

}
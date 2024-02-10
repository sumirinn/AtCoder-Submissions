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
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<vector<char>> g(h);
    repp(i, h)repp(j, w) g[i].push_back('.');

    int x = 0, y = 0, c = 0;
    rep(i, n){
        char pos = g[x][y];
        if(pos=='.'){
            g[x][y] = '#';
            c++;  c += 4; c %= 4;
            x += di[c]; x += h; x = x % h;
            y += dj[c]; y += w; y = y % w;
        }
        if(pos=='#'){
            g[x][y] = '.';
            c--; c += 4; c %= 4;
            x += di[c]; x += h; x = x % h;
            y += dj[c]; y += w; y = y % w;
        }
    }
    repp(i, h){
        repp(j, w) cout << g[i][j];
        cout << endl;
    }
}
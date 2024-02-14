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
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w; cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];

    int cnt = 0;
    int i = 0, j = 0;
    while((g[i][j]=='U' && i!=0) || (g[i][j]=='D' && i!=h-1) || (g[i][j]=='L' && j!=0) || (g[i][j]=='R' && j!=w-1)){
        if(g[i][j]=='U' && i!=0) i--;
        if(g[i][j]=='D' && i!=h-1) i++;
        if(g[i][j]=='L' && j!=0) j--;
        if(g[i][j]=='R' && j!=w-1) j++;
        cnt++;
        if(cnt==h*w+1){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << i+1 << " " << j+1 << endl;

}
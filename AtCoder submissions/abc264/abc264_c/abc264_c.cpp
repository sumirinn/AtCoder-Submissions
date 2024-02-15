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
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i, h1)rep(j, w1) cin >> a[i][j];
    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i, h2)rep(j, w2) cin >> b[i][j];

    rep(s, 1<<h1)rep(t, 1<<w1){
        vector<int> x, y;
        rep(i, h1)if(s>>i&1)x.push_back(i);
        rep(i, w1)if(t>>i&1)y.push_back(i);
        if(x.size()!=h2 || y.size()!=w2) continue;
        vector<vector<int>> c(h2, vector<int>(w2));
        rep(i, h2)rep(j, w2) c[i][j] = a[x[i]][y[j]];
        if(b==c){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
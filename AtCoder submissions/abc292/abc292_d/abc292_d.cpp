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
    int n, m; cin >> n >> m;
    vector<int> u(m);
    dsu uf(n);
    rep(i, m){
        int a; cin >> u[i] >> a; u[i]--; a--;
        uf.merge(a, u[i]);
    }

    vector<int> vertexs(n), edges(n);
    rep(i, n){
        vertexs[uf.leader(i)]++;
    }
    rep(i, m){
        edges[uf.leader(u[i])]++;
    }
    if(vertexs==edges) cout << "Yes" << endl;
    else cout << "No" << endl; 
}
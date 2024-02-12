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
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    int n = min(h, w);
    vector<int> ans(n);
    vector<P> center;
    for(int i=1; i<h-1; i++){
        for(int j=1; j<w-1; j++){
            if(c[i][j]=='#' && c[i-1][j-1]=='#' && c[i-1][j+1]=='#' && c[i+1][j-1]=='#' && c[i+1][j+1]=='#'){
                center.emplace_back(i, j);
            }
        }
    }

    for(auto[i, j] : center){
        int cnt = -2;
        while(i<h && j<w && c[i][j]=='#'){
            cnt++; i++; j++;
        }
        ans[cnt]++;
    }
    for(int i : ans) cout << i << " ";
    cout << endl;
}
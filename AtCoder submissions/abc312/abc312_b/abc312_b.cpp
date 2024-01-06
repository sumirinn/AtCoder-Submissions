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
//97~122

int main(){
    int n, m;
    char s[109][109];
    cin >> n >> m;
    rep(i, n)rep(j, m) cin >> s[i][j];

    int cnt = 0;
    auto f = [&](int i, int j) -> bool {
        repp(u, 3)repp(v, 3) if(s[i+u][j+v]=='.') return false;
        repp(u, 3)repp(v, 3) if(s[i+u+6][j+v+6]=='.') return false;
        repp(u, 4){
            if(s[i+3][j+u]=='#' || s[i+u][j+3]=='#' || s[i+5][j+5+u]=='#' || s[i+5+u][j+5]=='#') return false;
        }
        return true;
    };

    rep(i, n-8)rep(j, m-8)if(f(i, j)) cout << i << " " << j << endl;
}
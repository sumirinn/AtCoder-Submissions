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
    int h, w;
    int a[109][109];
    cin >> h >> w;
    rep(i,h)rep(j,w) cin >> a[i][j];

    rep(i,h){
        rep(j,w){
            if(a[i][j]==0) cout << '.';
            else cout << char(a[i][j]+ 'A' - 1);
        }
        cout << endl;
    }

}
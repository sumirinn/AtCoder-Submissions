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
    int n;
    cin >> n;
    int a[400009];
    rep(i, n*2+1) a[i] = 1;

    rep(i, n){
        int c;
        cin >> c;
        a[i*2] = c;
        a[i*2+1] = c;
    }

    int ans[400009];
    rep(i, n*2+1) ans[i] = 0;

    rep(i, n*2+1){
        if(i==1) continue;
        ans[i] = ans[a[i]] + 1;
    }

    rep(i, n*2+1) cout << ans[i] << endl;
}
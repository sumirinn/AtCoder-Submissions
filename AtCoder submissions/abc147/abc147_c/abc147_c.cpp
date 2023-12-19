#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n, a[20], x[20][20], y[20][20];

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]) cin >> x[i][j] >> y[i][j];
    }

    auto check = [&](int bit) -> bool {
        int lier[20];
        rep(i, n) lier[i] = 0;
        repp(i, n) if(bit & (1 << i)) lier[i+1] = 1;
        rep(i, n){
            if(lier[i]==1){
                rep(j, a[i]){
                    if(lier[x[i][j]]!=y[i][j]) return false;
                }
            }
        }

        return true;
    };

    int ans = 0;
    repp(bit, (1 << n)){
        if(check(bit)){
            int cnt = 0;
            repp(i, n) if(bit & (1<<i)) cnt++;
            ans = max(ans,cnt);
        }
    }

    cout << ans << endl;
}
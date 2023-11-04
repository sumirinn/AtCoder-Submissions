#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int t;
int n[109], ans[109];
long long a[109][109];

int main(){
    cin >> t;
    rep(i, t){
        cin >> n[i];
        rep(j, n[i]) cin >> a[i][j];
        rep(j, n[i]) if(a[i][j]%2==1) ans[i]++;
    }

    rep(i, t) cout << ans[i] << endl;
}
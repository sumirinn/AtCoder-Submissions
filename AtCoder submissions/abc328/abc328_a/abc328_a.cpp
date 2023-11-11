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

int n, x, s[10];

int main(){
    cin >> n >> x;
    rep(i, n) cin >> s[i];

    int ans = 0;
    rep(i, n){
        if(s[i]<=x) ans += s[i];
    }
    cout << ans << endl;
    
}

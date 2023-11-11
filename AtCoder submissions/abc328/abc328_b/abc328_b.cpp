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

int n, d[109];

int main(){
    cin >> n;
    rep(i, n) cin >> d[i];

    int ans = 0;

    rep(i, n){
        if(i<=9){
            if(i<=d[i]) ans++;
            if(i*11<=d[i]) ans++;
        }

        if(i/10==i%10){
            int q = i / 10;
            if(q<=d[i]) ans++;
            if(q*11<=d[i]) ans++;
        }
    }

    cout << ans << endl;

} 
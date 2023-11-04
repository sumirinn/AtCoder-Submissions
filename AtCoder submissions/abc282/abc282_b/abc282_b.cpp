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

int n, m;
char s[39][39];

int main(){
    cin >> n >> m;
    rep(i, n)rep(j, m) cin >> s[i][j];

    int ans = 0;

    rep(i, n){
        for(int j = i+1; j<=n; j++){
            bool clear = true;
            rep(k, m) if(s[i][k]=='x' && s[j][k]=='x') clear = false;
            if(clear) ans++;
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n, s, m, l;

int main(){
    cin >> n >> s >> m >> l;

    int ans = 1000000;

    rep(i, 17){
        rep(j, 13){
            rep(k, 9){
                if(6*i + 8*j + 12*k >= n) ans = min(ans, s*i+m*j+l*k);
            }
        }
    }

    cout << ans << endl;
}
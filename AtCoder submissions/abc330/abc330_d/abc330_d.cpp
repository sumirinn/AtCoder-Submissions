#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;
char s[2009][2009];

int main(){
    cin >> n;
    rep(i, n)rep(j, n) cin >> s[i][j];

    ll t[2009], y[2009];
    rep(i, n){
        ll tcnt = 0;
        ll ycnt = 0;
        rep(j, n){
            if(s[j][i]=='o') tcnt++;
            if(s[i][j]=='o') ycnt++;
        }

        t[i] = tcnt;
        y[i] = ycnt;
    }

    ll ans = 0;

    rep(i, n)rep(j, n)if(s[i][j]=='o') ans += (y[i]-1) * (t[j]-1);

    cout << ans << endl;
}
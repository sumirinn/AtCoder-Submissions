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

ll n, q, p[1009][1009], cnt[1009][1009];
ll a[200009], b[200009], c[200009], d[200009];

ll f(ll c, ll d){
    ll s = cnt[n][n]*(c/n)*(d/n) + cnt[n][d%n]*(c/n) + cnt[c%n][n]*(d/n) + cnt[c%n][d%n];
    return s;
}

int main(){
    cin >> n >> q;
    char s;
    rep(i, n)rep(j, n){
        cin >> s;
        if(s=='B') p[i][j] = 1;
        else p[i][j] = 0;
    }

    cnt[0][0] = 0;
    rep(i, n){
        cnt[i][0] = 0;
        cnt[0][i] = 0;
    }
    rep(i, n)rep(j, n) cnt[i][j] = p[i][j] + cnt[i-1][j];
    rep(i, n)rep(j, n) cnt[i][j] = cnt[i][j] + cnt[i][j-1];

    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    rep(i, q){
        c[i]++;
        d[i]++;
        ll ans = f(c[i], d[i]) - f(c[i], b[i]) - f(a[i], d[i]) + f(a[i], b[i]);
        cout << ans << endl;
    }
}
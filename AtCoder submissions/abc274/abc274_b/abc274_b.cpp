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

int h, w;
char c[1009][1009];

int main(){
    cin >> h >> w;
    rep(i, h)rep(j, w) cin >> c[i][j];

    int x[1009];
    rep(i, w) x[i] = 0;
    rep(i, h)rep(j, w)if(c[i][j]=='#') x[j]++;
    rep(i, w) cout << x[i] << " ";
    cout << endl;
}
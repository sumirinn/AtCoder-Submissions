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

int n, p, q, r, s, a[109], b[109], c[109];

int main(){
    cin >> n >> p >> q >> r >> s;
    rep(i, n) cin >> a[i];

    for(int i=p; i<=q; i++) b[i-p+1] = a[i];
    for(int i=r; i<=s; i++) c[i-r+1] = a[i];
    for(int i=p; i<=q; i++) a[i] = c[i-p+1];
    for(int i=r; i<=s; i++) a[i] = b[i-r+1];
    rep(i, n) cout << a[i] << " ";
    cout << endl;
}
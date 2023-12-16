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



int n, l, a[109];

int main(){
    cin >> n >> l;
    rep(i, n) cin >> a[i];

    int cnt = 0;
    rep(i, n) if(a[i]>=l) cnt++;

    cout << cnt << endl;
}
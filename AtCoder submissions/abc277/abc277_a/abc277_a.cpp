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

int n, x, p[109];

int main(){
    cin >> n >> x;
    rep(i, n) cin >> p[i];

    int k = 0;

    rep(i, n) if(p[i]==x) k = i;

    cout << k << endl;
}
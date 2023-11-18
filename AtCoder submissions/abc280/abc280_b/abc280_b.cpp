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

int n, s[19];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];

    s[0] = 0;
    rep(i, n) cout << s[i] - s[i-1] << " ";
    cout << endl;
}
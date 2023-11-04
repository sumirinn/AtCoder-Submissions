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

int a, b;

int main(){
    cin >> a >> b;
    int ans = 1;
    rep(i, b) ans *= a;
    cout << ans << endl;
}
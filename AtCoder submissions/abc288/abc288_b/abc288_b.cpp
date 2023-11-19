#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)


int n, k;
string s[109];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> s[i];

    sort(s + 1, s + k + 1);
    rep(i, k) cout << s[i] << endl;
}
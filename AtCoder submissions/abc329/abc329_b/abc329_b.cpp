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

int n, a[109];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    int aa = 0;
    rep(i, n) aa = max(aa, a[i]);
    rep(i, n) if(a[i]==aa) a[i]=0;
    int aaa = 0;
    rep(i, n) aaa = max(aaa, a[i]);

    cout << aaa << endl;
}
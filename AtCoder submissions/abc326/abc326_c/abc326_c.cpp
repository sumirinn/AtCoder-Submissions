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

int n;
long long m, a[300009];

int main(){
    cin >> n >> m;
    vector<long long> v;
    rep(i, n){
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    sort(a+1, a+n+1);
    int ans = 0;

    rep(i, n){
        int pos = lower_bound(a+1, a+n+1, m+a[i]) - a;
        pos = pos - i;
        ans = max(ans, pos);
    }

    cout << ans << endl;

}
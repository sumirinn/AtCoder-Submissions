#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
//97~122

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    repp(i, n) cin >> a[i] >> b[i];
    repp(i, n) b[i] += a[i];

    vector<int> ans(n);
    repp(i, n) ans[i] = i;
    stable_sort(ans.begin(), ans.end(), [&](int i, int j){
        return (ll)a[i]*b[j] > (ll)a[j]*b[i];
    });

    repp(i, n) cout << ans[i] + 1 << " ";
    cout << endl;
}
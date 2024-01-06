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
//97~122(a~z)

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    
    map<vector<int>, ll> dp;
    dp[vector<int>(k)] = 0;
    repp(i, n){
        int c;
        vector<int> a(k);
        cin >> c;
        repp(j, k) cin >> a[j];
        auto old = dp;
        for(auto [_d,val] : old) {
            vector<int> d = _d;
            repp(j, k) d[j] = min(d[j]+a[j], p);
            if(dp.count(d)) dp[d] = min(dp[d], val+c);
            else dp[d] = val + c;
        }
    }

    vector<int> t(k,p);
    if(dp.count(t)) cout << dp[t] << endl;
    else cout << -1 << endl;
}
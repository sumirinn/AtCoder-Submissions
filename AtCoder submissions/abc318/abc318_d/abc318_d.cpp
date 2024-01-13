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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> d(n+1, vector<ll>(n+1));
    repp(i, n){
        for(int j=i+1; j<n; j++){
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    
    if(n%2==1) n++;

    ll ans = 0;
    vector<bool> used(n);
    auto f = [&](auto f, ll w) -> void {
        ans = max(ans, w);
        int i = 0;
        while(i<n && used[i]) i++;
        used[i] = true;
        if(i==n) return;
        for(int j=i+1; j<n; j++){
            if(used[j]) continue;
            used[j] = true;
            f(f, w+d[i][j]);
            used[j] = false;
        }
        used[i] = false;
    };

    f(f, 0);
    cout << ans << endl;
}
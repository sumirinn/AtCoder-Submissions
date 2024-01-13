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
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    repp(i, m){
        int c;
        cin >> c;
        repp(j, c){
            int a;
            cin >> a;
            a--;
            s[i] |= 1<<a;
        }
    }

    int ans = 0;
    repp(i, 1<<m){
        int t = 0;
        repp(j, m)if(i>>j & 1) t |= s[j];
        if(t==(1<<n)-1) ans++;
    }

    cout << ans << endl;
}
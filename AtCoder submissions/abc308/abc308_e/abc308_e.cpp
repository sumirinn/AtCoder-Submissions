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
    vector<int> a(n);
    repp(i, n) cin >> a[i];
    string s;
    cin >> s;

    ll ans = 0;
    vector<int> m(3), x(3);
    repp(k, n) if(s[k]=='X') x[a[k]]++;
    auto mex = [&](int a, int b, int c) {
        set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        int res = 0;
        while(s.count(res)) res++;
        return res;
    };

    repp(j, n){
        if(s[j]=='E'){
            repp(i, 3)repp(k, 3){
                ll now = (ll)m[i]*x[k];
                ans += now*mex(i, a[j], k);
            }
        }

        if(s[j]=='M') m[a[j]]++;
        if(s[j]=='X') x[a[j]]--;
    }

    cout << ans << endl;
}

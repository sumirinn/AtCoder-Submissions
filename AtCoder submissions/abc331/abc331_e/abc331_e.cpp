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

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    repp(i, n) cin >> a[i];
    repp(i, m) cin >> b[i];
    vector<unordered_set<int>> st(n);
    repp(i, l){
        int c, d;
        cin >> c >> d;
        c--; d--;
        st[c].insert(d);
    }

    vector<pair<int, int>> v;
    repp(i, m){
        v.push_back(make_pair(b[i], i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = 0;
    repp(i, n){
        repp(j, m){
            int pos = v[j].second;
            if(st[i].count(pos)!=0) continue;
            ans = max(ans, a[i]+b[pos]);
            break;
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n; cin >> n;
    map<string, string>  to;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i] >> t[i];
    rep(i, n) to[s[i]] = t[i];

    set<string> used;
    for(string ss : s){
        string ns = ss;
        while(!used.count(ns)){
            used.insert(ns);
            auto it = to.find(ns);
            if(it==to.end()) break;
            ns = it->second;
            if(ns==ss){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
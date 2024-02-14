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
    set<P> st;
    vector<P> ps;
    rep(i, 9){
        string s; cin >> s;
        rep(j, 9){
            if(s[j]=='#'){
                st.emplace(i, j);
                ps.emplace_back(i, j);
            }
        }
    }

    int n = ps.size();
    int ans = 0;
    rep(ai, n)rep(bi, n)if(ai!=bi){
        P a = ps[ai], b = ps[bi];
        int di = b.first - a.first;
        int dj = b.second - a.second;
        P c(b.first-dj, b.second+di);
        P d(c.first-di, c.second-dj);
        if(st.count(c) && st.count(d)) ans++;
    }
    cout << ans / 4 << endl;
}
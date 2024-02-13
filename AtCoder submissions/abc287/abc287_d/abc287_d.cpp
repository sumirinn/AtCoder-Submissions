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
    string s, t; cin >> s >> t;

    int n = s.size(), m = t.size();
    int cnt = 0;

    auto f = [&](char u, char v) -> bool {
        if(u==v || u=='?' || v=='?') return true;
        return false;
    };

    rep(i, m) if(f(t[i], s[n-m+i])) cnt++;
    if(cnt==m) cout << "Yes" << endl;
    else cout << "No" << endl;
    rep(i, m){
        if(f(t[i], s[n-m+i])) cnt--;
        if(f(t[i], s[i])) cnt++;
        if(cnt==m) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
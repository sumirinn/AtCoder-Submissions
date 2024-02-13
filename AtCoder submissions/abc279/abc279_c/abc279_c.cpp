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

int h, w;
vector<string> input(){
    vector<string> s(h), x(w, string(h, '?'));
    rep(i, h) cin >> s[i];
    rep(i, h)rep(j, w) x[j][i] = s[i][j];
    sort(x.begin(), x.end());
    return x;
}

int main(){
    cin >> h >> w;
    auto s = input();
    auto t = input();
    if(s==t) cout << "Yes" << endl;
    else cout << "No" << endl;
}
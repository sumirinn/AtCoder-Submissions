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
using P = pair<int, ll>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    cin >> n;
    vector<pair<string, int>> s(n);
    rep(i, n){
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s.begin(), s.end());
    vector<int> ans(n);
    rep(i, n-1){
        auto [a, ai] = s[i];
        auto [b, bi] = s[i+1];
        int now = 0;
        while(now<a.size() && now<b.size() && a[now]==b[now]) now++;
        ans[ai] = max(ans[ai], now);
        ans[bi] = max(ans[bi], now);
    }
    
    rep(i, n) cout << ans[i] << endl;
}
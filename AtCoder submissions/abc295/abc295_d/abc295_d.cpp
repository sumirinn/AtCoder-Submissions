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
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    string s; cin >> s; int n = s.size();
    vector<vector<int>> x(n+1, vector<int>(10));
    rep(i, n){
        int c = s[i] - '0';
        x[i+1] = x[i];
        x[i+1][c] ^= 1;
    }

    map<vector<int>, int> mp;
    rep(i, n+1) mp[x[i]]++;

    ll ans = 0;
    for(auto p : mp){
        ll num = p.second;
        ans += num*(num-1) / 2;
    }

    cout << ans << endl;
}
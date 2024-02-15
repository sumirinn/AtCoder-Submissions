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
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    rep(i, n) c[i]--;
    rep(i, n) c.push_back(c[i]);
    vector<int> tot(n);
    rep(i, n) tot[c[i]]++;

    vector<int> ball(n), box(n);
    int remain = m, ans = 0;

    auto add = [&](int i, int num) {
        ans -= min(tot[i], box[i]*k);
        remain += box[i];
        ball[i] += num;
        box[i] = (ball[i]+k-1) / k;
        remain -= box[i];
        ans += min(tot[i], box[i]*k);
    };
    int r = 0;
    rep(l, n){
        while(r<l+n && remain){
            add(c[r], 1);
            r++;
        }
        cout << ans << endl;
        add(c[l], -1);
    }

}
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
    vector<ll> o, e;
    rep(i, n){
        int a; cin >> a;
        if(a%2==1) o.push_back(a);
        else e.push_back(a);
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    ll ans = -1;
    if(o.size()>=2) ans = o[o.size()-1] + o[o.size()-2];
    if(e.size()>=2) ans = max(ans, e[e.size()-1] + e[e.size()-2]);
    cout << ans << endl;
}
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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll g = 0;
    rep(i, n) g = gcd(g, a[i]);

    int ans = 0;

    rep(i, n) {
        a[i] /= g;
        while(a[i]%2==0){
            a[i] /= 2;
            ans++;
        }
        while(a[i]%3==0){
            a[i] /= 3;
            ans++;
        }
        if(a[i]!=1){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}

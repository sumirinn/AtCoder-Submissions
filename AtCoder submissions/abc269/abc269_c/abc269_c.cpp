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
    ll n;
    cin >> n;

    vector<ll> l;
    ll cnt = 0;
    while(n>=1){
        if(n%2==1) l.push_back(ll(1)<<cnt);
        n /= 2;
        cnt++;
    }
    int m = l.size();
    rep(i, 1<<m){
        ll ans = 0;
        int p = i;
        int c = 0;
        while(p>=1){
            if(p%2==1) ans += l[c];
            p /= 2;
            c++;
        }
        cout << ans << endl;
    }
}
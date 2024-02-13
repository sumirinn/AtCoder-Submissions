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

    map<int, ll> add;
    int base = 0;
    rep(i, n){
        int a; cin >> a;
        add[i+1] = a;
    }

    int q; cin >> q;
    rep(qi, q){
        int t; cin >> t;
        if(t==1){
            int x; cin >> x;
            base = x;
            add = map<int, ll>();
        }
        if(t==2){
            int i, x; cin >> i >> x;
            add[i] += x;
        }
        if(t==3){
            int i; cin >> i;
            ll ans = base + add[i];
            cout << ans << endl;
        }
    }
}
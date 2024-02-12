#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m; cin >> n >> m;

    fenwick_tree<ll> d(n+1);
    auto f = [&](int l, int r, ll x) -> void{
        d.add(l, x);
        d.add(r, -x);
    };

    repp(i, n){
        int a; cin >> a;
        f(i, i+1, a);
    }

    repp(mi, m){
        int b; cin >> b;
        ll x = d.sum(0, b+1);
        f(b, b+1, -x);

        ll c = x/n; x %= n;
        f(0, n, c);
        b++;
        if(b+x<n) f(b, b+x, 1);
        else{
            f(b, n, 1);
            f(0, b+x-n, 1);
        }
    }

    repp(i, n) cout << d.sum(0, i+1) << " ";
    cout << endl;
}
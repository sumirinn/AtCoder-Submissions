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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int n, m;
    cin >> n >> m;
    dsu uf(n);

    int a, b;
    int ans = 0;
    rep(i, m){
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)) ans++;
        else uf.merge(a, b);
    }

    cout << ans << endl;
}

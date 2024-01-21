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
const int dj[] = {0, -1, 0, 1};
const int inf = 1001001001;
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    repp(i, n) cin >> a[i];
    set<ll> s;
    repp(i, n) s.insert(a[i]);
    int ans = 0, book = 1, p = 0;
    while(book<=n){
        if(s.count(book)) p++;
        else p += 2;
        if(p<=n) ans = book;
        book++;
    }
    cout << ans << endl;
}
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
int inf = 1001001001;
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    repp(i, n) cin >> a[i];
    auto b = a;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> k(n);
    repp(i, n){
        int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        k[a.size()-1-pos]++;
    }
    repp(i, n) cout << k[i] << endl;
}
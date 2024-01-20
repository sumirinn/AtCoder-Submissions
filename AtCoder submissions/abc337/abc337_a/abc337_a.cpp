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
    int n, x[109], y[109];
    cin >> n;
    rep(i, n) cin >> x[i] >> y[i];

    int ans1 = 0, ans2 = 0;
    rep(i, n){
        ans1 += x[i];
        ans2 += y[i];
    }
    if(ans1>ans2) cout << "Takahashi" <<endl;
    if(ans1==ans2) cout << "Draw" << endl;
    if(ans1<ans2) cout << "Aoki" << endl;
}
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> sx;
    sx.insert(0);
    rep(i, n){
        if(i%2==1) continue;
        if(i==0){
            sx.erase(0);
            sx.insert(a[0]);
            continue;
        }
        auto SX = sx;
        for(int u : SX){
            sx.erase(u);
            sx.insert(u+a[i]);
            sx.insert(u-a[i]);
        }
    }

    
    set<int> sy;
    sy.insert(0);
    rep(i, n){
        if(i%2==0) continue;
        auto SY = sy;
        for(int u : SY){
            sy.erase(u);
            sy.insert(u+a[i]);
            sy.insert(u-a[i]);
        }
    }

    if(sx.count(x) && sy.count(y)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
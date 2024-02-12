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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int m; cin >> m;
    set<int> b;
    rep(i, m){
        int moti; cin >> moti;
        b.insert(moti);
    }
    int x; cin >> x; 

    vector<bool> can_step(x+1);
    can_step[0] = true;

    rep(i, x+1){
        if(can_step[i]){
            rep(j, n){
                int nex = i + a[j];
                if(nex<=x && !(b.count(nex))) can_step[nex] = true;
            }
        }
    }

    if(can_step[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
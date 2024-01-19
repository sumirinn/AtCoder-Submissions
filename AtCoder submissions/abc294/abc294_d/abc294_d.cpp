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
//97~122(a~z)

int main(){
    int n, q;
    cin >> n >> q;

    set<int> s;
    int p = 1;
    rep(qi, q){
        int Q;
        cin >> Q;

        if(Q==1){
            if(p<=n) s.insert(p);
            p++;
        }

        if(Q==2){
            int x;
            cin >> x;
            s.erase(x);
        }

        if(Q==3){
            cout << *begin(s) <<endl;
        }
    }
}
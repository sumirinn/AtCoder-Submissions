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
    int Q; cin >> Q;

    queue<int> q;
    q.push(1);
    mint ans = 1;

    rep(qi, Q){
        int type; cin >> type;
        if(type==1){
            int x; cin >> x;
            q.push(x);
            ans = ans*10 + x;
        }
        if(type==2){
            int x = q.front(); q.pop();
            ans -= mint(10).pow(q.size())*x;
        }
        if(type==3){
            cout << ans.val() << endl;
        }
    }
}
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
    int n, q; cin >> n >> q;
    int cnt = n;
    vector<unordered_set<int>> to(n);

    repp(qi, q){
        int t; cin >> t;
        if(t==1){
            int a, b; cin >> a >> b; a--; b--;
            if(!to[a].size()) cnt--;
            if(!to[b].size()) cnt--;
            to[a].insert(b);
            to[b].insert(a);
        }
        if(t==2){
            int a; cin >> a; a--;
            if(to[a].size()!=0){
                for(int i : to[a]){
                    if(to[i].size()==1) cnt++;
                    to[i].erase(a);
                }
                to[a] = unordered_set<int>();
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
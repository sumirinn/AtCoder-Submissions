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

    vector<vector<int>> v(n+1);
    vector<vector<int>> s(200000+1);

    rep(qi, q){
        int Q;
        cin >> Q;

        if(Q==1){
            int i, j;
            cin >> i >> j;
            v[j].push_back(i);
            s[i].push_back(j);
        }

        if(Q==2){
            int i;
            cin >> i;
            sort(v[i].begin(), v[i].end());
            repp(k, v[i].size()){
                cout << v[i][k] << " ";
            }
            cout << "\n";
        }

        if(Q==3){
            int i;
            cin >> i;
            sort(s[i].begin(), s[i].end());
            s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
            repp(k, s[i].size()) cout << s[i][k] << " ";
            cout << "\n";
        }
    }
}
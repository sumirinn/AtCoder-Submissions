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
    vector<int> v(5);
    repp(i, 5) cin >> v[i];
    sort(v.begin(), v.end());
    if(v[0]==v[1] && v[1]==v[2] && v[3]==v[4]){
        cout << "Yes" << endl;
        return 0;
    }
    if(v[0]==v[1] && v[2]==v[3] && v[3]==v[4]){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
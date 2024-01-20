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
    map<int , int> m;
    int s = 0;
    rep(i, n){
        int b = 0;
        cin >> b;
        if(b==-1){
            s = i;
            continue;
        }
        m[b] = i;
    }

    int cnt = 0;
    while(cnt<n){
        cout << s << " ";
        s = m[s];
        cnt++;
    }
    cout << endl;
}
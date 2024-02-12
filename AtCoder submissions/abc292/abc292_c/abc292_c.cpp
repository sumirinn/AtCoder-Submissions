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

    ll ans = 0;

    for(int i= 1; i<n; i++){
        int X = i, Y = n-i;
        ll x = 0, y = 0;
        for(int j= 1; j*j<=X; j++){
            if(X%j==0){
                x++;
                if(X!=j*j) x++;
            }
        }
        for(int j=1; j*j<=Y; j++){
            if(Y%j==0){
                y++;
                if(Y!=j*j) y++;
            }
        }
        ans += x*y;
    }

    cout << ans << endl;
}
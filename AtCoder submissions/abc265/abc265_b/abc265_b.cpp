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
    int n, m;
    ll t;
    cin >> n >> m >> t;
    ll a[100009];
    rep(i, n-1) cin >>a[i];
    a[n+1] = 0;
    int x[100009];
    ll y[100009];
    rep(i, m) cin >> x[i] >> y[i];

    int pos = 1;
    t -= a[pos];
    int b = 1;
    while(t>0 && pos<n){
        if(x[b]==pos+1){
            t += y[b];
            b++;
        }
        t -= a[pos+1];
        if(t<=0) break;
        pos++;
    }

    if(pos==n) cout << "Yes" << endl;
    else cout << "No" << endl;
}
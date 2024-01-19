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
    int n, m;
    ll d;
    cin >> n >> m >>d;
    vector<ll> a(n), b(m);
    repp(i, n) cin >> a[i];
    repp(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = n-1, j = m-1;
    while(i>=0 && j>=0){
        if(a[i]>=b[j]){
            if(a[i]-b[j]<=d) break;
            i--;
        }
        if(a[i]<b[j]){
            if(b[j]-a[i]<=d) break;
            j--;
        }
    }

    if(i<0 || j<0) cout << -1 << endl;
    else cout << a[i] + b[j] << endl;
}
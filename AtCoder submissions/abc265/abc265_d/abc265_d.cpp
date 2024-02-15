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
const ll INF = 1e18;
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(3), s(n+1);
    rep(i, 3) cin >> b[i];
    rep(i, n) cin >> a[i];
    rep(i, n) s[i+1] = s[i] + a[i];

    set<ll> st;
    rep(i, n+1) st.insert(s[i]);

    rep(i, n+1){
        ll pos = s[i];
        rep(j, 3){
            pos += b[j];
            if(!st.count(pos)) break;
            if(j==2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
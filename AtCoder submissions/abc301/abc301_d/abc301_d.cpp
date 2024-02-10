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
    string s; cin >> s;
    ll n; cin >> n;

    ll t = 0;
    repp(i, s.size()) if(s[i]=='1') t+= (ll(1)<<(s.size()-i-1));
    if(t>n){
        cout << -1 << endl;
        return 0;
    }
    repp(i, s.size()) if(s[i]=='?') if(t+(ll(1)<<(s.size()-1-i))<=n) t += (ll(1)<<(s.size()-i-1));
    cout << t << endl;
}
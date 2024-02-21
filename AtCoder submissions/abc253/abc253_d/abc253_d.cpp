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
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    ll l = lcm(a, b);
    ll ca = l/a, cb = l/b;
    ll num = l*(l+1)/2 - a*ca*(ca+1)/2 - b*cb*(cb+1)/2 + l;
    ll cntt = l - ca -cb + 1;
    ll dig = n / l;
    ans += num * dig + l*cntt*dig*(dig-1)/2;

    ll c = n % l;
    ll x = c/a, y = c/b;
    ll munn = c*(c+1)/2 - a*x*(x+1)/2 - b*y*(y+1)/2;
    ans += munn;

    ll cnt = c - x - y;
    //cout << l << " " << dig << " " << cnt << " " << c << endl;
    ans += l*dig*cnt;
    
    cout << ans << endl;
}
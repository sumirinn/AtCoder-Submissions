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
using MP = map<int, vector<int>>;
using mint = modint998244353;
using P = pair<mint, ll>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int & x, int y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    ll a, b;
    cin >> a >> b;
    ll l=0, r=1e18;
    auto f = [&](ll x){
        double res = a/sqrt(1+x) + (double)x*b;
        return res;
    };
    while(l+3<=r){
        ll c1 = (l*2+r)/3;
        ll c2 = (l+r*2)/3;
        if(f(c1)<f(c2)) r = c2;
        else l = c1;
    }

    double ans = min({f(l), f(l+1), f(r)});
    cout << fixed << setprecision(20) << ans << endl;
}
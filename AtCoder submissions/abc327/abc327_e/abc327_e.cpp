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
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int main(){
    int n;
    cin >> n;
    vector<double> p(n);
    rep(i, n) cin >> p[i];

    vector<double> dp(n+1, -1001001001);
    dp[0] = 0;

    rep(i, n){
        vector<double> pre(n+1, -1001001001);
        swap(dp, pre);
        rep(j, n+1) if(pre[j]!=-1001001001){
            dp[j] = max(dp[j], pre[j]);
            if(j+1<=n) dp[j+1] = max(dp[j+1], pre[j]*0.9+p[i]);
        }
    }

    double ans = -1001001001, x = 1;
    repp(i, n){
        double now = dp[i];
        now /= x;
        now -= 1200/sqrt(i);
        ans = max(ans, now);
        x = x*0.9 + 1;
    }

    cout << fixed << setprecision(10) << ans << endl;


}
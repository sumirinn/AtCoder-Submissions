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
void chmax(int& x, int y) {x = max(x, y);} // change max
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


ll dp[1009][1009];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    rep(i, h)rep(j, w) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, h){
        rep(j, w){
            if(a[i][j]=='#') continue;
            rep(v, 2){
                int ni = i + di[v], nj = j + dj[v];
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(a[ni][nj]=='#') continue;
                dp[ni][nj] += dp[i][j];
                dp[ni][nj] %= ll(1e9 + 7);
            }
        }
    }

    cout << dp[h-1][w-1] << endl;

}

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
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int dp[3009][3009] = {0};

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    rep(i, n)rep(j, m){
        if(s[i]==t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
        chmax(dp[i+1][j+1], dp[i+1][j]);
        chmax(dp[i+1][j+1], dp[i][j+1]);
    }

    string ans = "";
    while(n>0 && m>0){
        if(dp[n][m]==dp[n-1][m]) n--;
        else if(dp[n][m]==dp[n][m-1]) m--;
        else {
            ans += s[n-1];
            n--; m--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
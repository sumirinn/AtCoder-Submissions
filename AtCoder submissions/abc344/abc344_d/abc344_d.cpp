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
using P = pair<ll, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int dp[109][109];

int main(){
    string t;
    cin >> t;
    int m = t.size();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<string>> s(n);
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            string S;
            cin >> S;
            s[i].push_back(S);
        }
    }

    rep(i, n+1)rep(j,m+1) dp[i][j] = inf;
    dp[0][0] = 0;
    repp(i, n){
        rep(j,m+1) chmin(dp[i][j], dp[i-1][j]);
        rep(l,a[i-1]){
            string nex = s[i-1][l];
            int nl = nex.size();
            rep(j, m-nl+1){
                bool ok = true;
                rep(c, nl) if(t[j+c]!=nex[c]){
                    ok = false;
                    break;
                }
                if(ok) chmin(dp[i][j+nl], dp[i-1][j] + 1); 
            }
        }
    }

    if(dp[n][m]>10010010) dp[n][m] = -1;
    cout << dp[n][m] << endl;
}
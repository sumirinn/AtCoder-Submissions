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
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    bool dp[109][10009];
    rep(i, n+1)rep(j, s+1) dp[i][j] = false;
    dp[0][0] = true;

    rep(i, n)rep(j, s+1){
        if(dp[i][j]){
            int nja = j + a[i], njb = j + b[i];
            if(nja<=s) dp[i+1][nja] = true; 
            if(njb<=s) dp[i+1][njb] = true;
        }
    }

    if(!dp[n][s]){
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    string ans = "";
    for(int i = n-1; i>=0; i--){
        if( s-a[i]>=0 && dp[i][s-a[i]]){
            ans += 'H';
            s -= a[i];
        }else{
            ans+= 'T';
            s -= b[i];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
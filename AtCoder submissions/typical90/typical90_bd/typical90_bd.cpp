#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
    dp[0][0] = true;
    repp(i,n){
        cin >> a[i-1] >> b[i-1];
        for(int j=s; j>=0; j--){
            if(dp[i-1][j]){
                if(j+a[i-1]<=s) dp[i][j+a[i-1]] = true;
                if(j+b[i-1]<=s) dp[i][j+b[i-1]] = true;
            }
        }
    }

    if(!dp[n][s]){
        cout << "Impossible" << endl;
        return 0;
    }

    string ans = "";
    for(int i=n; i>=1; i--){
        if( s-a[i-1]>=0 && dp[i-1][s-a[i-1]]){
            s -= a[i-1];
            ans += 'A';
        }
        else{
            s -= b[i-1];
            ans += 'B';
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
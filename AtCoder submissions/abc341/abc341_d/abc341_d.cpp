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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll g = gcd(n, m);
    ll l = n*m / g;
    
    if(g==1) ll g = n * m;
    ll a = l / n - 1;
    ll b = l / m - 1;
    ll c = a + b;
    ll d = (k-1) / c;
    ll e = (k-1) % c;
    ll ans = l * d;
    e++;
    ll h = 1, r = l;
    while(r-h>=1){
        ll M = (h+r) / 2;
        ll cnt = M / n; 
        cnt += M / m;
        if(cnt<e) h = M+1;
        if(e<cnt) r = M-1;
        if(cnt==e){
            if(M%n==0 && M%m!=0){
                h = M;
                r = M;
                continue;
            }
            if(M%n!=0 && M%m==0){
                h = M;
                r = M;
                continue;
            }
            r = M -1;
        }
    }

    cout << ans + r << endl;

}
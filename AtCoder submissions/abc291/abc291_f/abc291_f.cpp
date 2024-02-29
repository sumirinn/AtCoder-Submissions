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
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
using mint = modint;//998244353;
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<int> d1(n, inf), dn(n, inf);
    d1[0] = 0; dn[n-1] = 0;
    rep(i, n)rep(j, m)if(s[i][j]=='1') chmin(d1[i+j+1], d1[i]+1);
    for(int i=n-1; i>=0; i--)rep(j, m)if(s[i][j]=='1') chmin(dn[i], dn[i+j+1]+1);

    repp(v, n-2){
        int ans = inf;
        for(int l=v-m; l<v; l++){
            if(l<0) continue;
            for(int r=v+1; r<=v+m; r++){
                if(r>=n || r-l-1>=m) break;
                if(s[l][r-l-1]=='1') chmin(ans, d1[l]+dn[r]+1);
            }
        }
        if(ans==inf) ans = -1;
        cout << ans << " ";
    }
    cout << endl;
}
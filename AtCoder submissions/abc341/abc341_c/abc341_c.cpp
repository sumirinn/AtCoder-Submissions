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
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(i, h)rep(j, w){
        if(s[i][j]=='#') continue;
        bool ok = true;
        int ni = i, nj = j;
        rep(k, n){
            if(!ok) continue;
            if(t[k]=='U') ni--;
            if(t[k]=='D') ni++;
            if(t[k]=='L') nj--;
            if(t[k]=='R') nj++;
            if(ni<0 || nj<0 || ni>=h || nj>=w){
                ok = false;
                continue;
            }
            if(s[ni][nj]=='#') ok = false;
        }
        if(ok) ans++;
    }

    cout << ans << endl;
}
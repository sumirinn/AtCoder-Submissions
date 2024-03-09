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
using P = pair<int, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
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
    int n;
    string t;
    cin >> n >> t;

    string s = t.substr(0, n);
    t = t.substr(n);
    reverse(t.begin(), t.end());

    string a = s + t;
    string b = t + s;
    auto za = z_algorithm(a);
    auto zb = z_algorithm(b);
    rep(i, n){
        if(i && za[n*2-i]!=i) continue;
        int j = n-i;
        if(j && zb[n*2-j]!=j) continue;
        string ans = s.substr(0, i);
        reverse(s.begin(), s.end());
        ans += s.substr(0, j);
        cout << ans << endl;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
}
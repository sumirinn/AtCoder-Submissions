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
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ax -= cx; ay -= cy;
    bx -= cx; by -= cy;
    if(bx<0) ax *= -1, bx *= -1;
    if(by<0) ay *= -1, by *= -1;
    if(by==0) swap(ax, ay), swap(bx, by);

    auto dist = [&](ll x, ll y) -> ll{
        if(ax==x && ay==y) return 0;
        ll res = abs(ax-x) + abs(ay-y);
        if(ax==x && bx==x) if((ay<by) != (y<by)) res += 2;
        if(ay==y && by==y) if((ax<bx) != (x<bx)) res += 2;
        return res;
    };

    if(bx==0){
        ll ans = dist(bx, by+1) + by;
        cout << ans << endl;
        return 0;
    }

    ll ans = min(dist(bx, by+1), dist(bx+1, by));
    ans += bx + by + 2;
    cout << ans << endl;
}
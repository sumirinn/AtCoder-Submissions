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
using P = pair<ll, ll>;
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    multiset<int> s, t;
    rep(i, k) s.insert(0);
    rep(i, n-k) t.insert(0);
    ll ans = 0;

    auto add = [&](int x) {
        s.insert(x); ans += x;
        int y = *s.begin();
        s.erase(s.find(y)); ans -= y;
        t.insert(y);
    };

    auto del = [&](int x) {
        if(s.find(x)!=s.end()){
            s.erase(s.find(x)); ans -= x;
            int y = *t.rbegin();
            t.erase(t.find(y));
            s.insert(y); ans += y;
        }else{
            t.erase(t.find(x));
        }
    };

    rep(qi, q){
        int x, y;
        cin >> x >> y;
        x--;
        add(y);
        del(a[x]);
        a[x] = y;
        cout << ans << '\n';
    }
}
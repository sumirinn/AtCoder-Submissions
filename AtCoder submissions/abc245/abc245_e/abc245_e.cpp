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
    int n, m;
    cin >> n >> m;
    vector<P> p(n), q(m);
    rep(i, n) cin >> p[i].first;
    rep(i, n) cin >> p[i].second;
    rep(i, m) cin >> q[i].first;
    rep(i, m) cin >> q[i].second;
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());

    multiset<int> s;
    int qi = 0;
    rep(i, n){
        auto [x, y] = p[i];
        while(qi<m && q[qi].first>=x){
            s.insert(q[qi].second);
            qi++;
        }
        auto it = s.lower_bound(y);
        if(it==s.end()){
            cout << "No" << endl;
            return 0;
        }
        s.erase(it);
    }

    cout << "Yes" << endl;
}
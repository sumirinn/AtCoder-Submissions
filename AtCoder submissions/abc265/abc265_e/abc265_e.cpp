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
using P = pair<ll, ll>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
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

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> a(3);
    rep(i, 3) cin >> a[i].first >> a[i].second;
    set<P> st;
    rep(i, m){
        ll x, y;
        cin >> x >> y;
        st.emplace(x, y);
    }

    map<P, mint> dp;
    dp[P(0,0)] = 1;
    rep(i, n){
        map<P, mint> pre;
        swap(pre, dp);
        for(auto[r, cnt] : pre){
            rep(j, 3){
                P nr = r;
                nr.first += a[j].first;
                nr.second += a[j].second;
                if(st.count(nr)) continue;
                dp[nr] += cnt;
            }
        }
    }

    mint ans = 0;
    for(auto[r, cnt]: dp) ans += cnt;
    cout << ans.val() << endl;
}
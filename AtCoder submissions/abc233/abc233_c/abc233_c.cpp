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
    int n; ll x;
    cin >> n >> x;
    vector<vector<ll>> a(n);
    rep(i, n){
        int l; cin >> l;
        rep(j, l){
            ll A;
            cin >> A;
            a[i].push_back(A);
        }
    }

    map<ll, ll> dp;
    rep(i, a[0].size()) dp[a[0][i]]++;
    //for(auto[u, v]: dp) cout << u << " " << v << endl;
    repp(i, n-1){
        auto pre = dp;
        dp.clear();
        for(auto [u, v] : pre){
            rep(j, a[i].size()){
                ll nex = u * a[i][j];
                if(nex>x) continue;
                dp[nex] += v;
            }
        }
    }
    //for(auto[u, v]: dp) cout << u << " " << v << endl;
    //cout << x << endl;
    cout << dp[x] << endl;
}
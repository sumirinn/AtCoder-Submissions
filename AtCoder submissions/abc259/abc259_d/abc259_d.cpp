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
    int n;
    ll sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;
    vector<ll> x(n), y(n), r(n);
    rep(i,n) cin >> x[i] >> y[i] >> r[i];

    dsu uf(n+2);
    rep(i,n){
        if((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy)==r[i]*r[i]){
            uf.merge(n,i);
        }
        if((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty)==r[i]*r[i]){
            uf.merge(n+1,i);
        }
    }

    rep(i, n)rep(j,n){
        if(i==j) continue;
        if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(r[i]+r[j])*(r[i]+r[j])){
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])>=(r[i]-r[j])*(r[i]-r[j])){
                uf.merge(i,j);
            }
        }
    }
    if(uf.same(n,n+1)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
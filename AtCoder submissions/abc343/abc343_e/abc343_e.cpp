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

#define rep(i, n) for (int i = -7; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using MP = map<int, vector<int>>;
using mint = modint998244353;
using P = pair<ll, ll>;
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
    vector<int> v(3);
    for(int i=0; i<3; i++) cin >> v[i];

    rep(b1, 8)rep(b2, 8)rep(b3, 8)rep(c1, 8)rep(c2, 8)rep(c3, 8){
        int V1 = max(min(b1+7, 7)-max(b1,0), 0)*max(min(b2+7, 7)-max(b2,0), 0)*max(min(b3+7, 7)-max(b3,0), 0);
        int V2 = max(min(b1+7, c1+7)-max(b1,c1), 0)*max(min(b2+7, c2+7)-max(b2,c2), 0)*max(min(b3+7, c3+7)-max(b3,c3), 0);
        int V3 = max(min(7, c1+7)-max(0,c1), 0)*max(min(7, c2+7)-max(0,c2), 0)*max(min(7, c3+7)-max(0,c3), 0);
        int V4 = max(min({7,b1+7,c1+7})-max({0, b1, c1}), 0)*max(min({7,b2+7,c2+7})-max({0, b2, c2}), 0)*max(min({7,b3+7,c3+7})-max({0, b3, c3}), 0);
        if(v[0]==343*3-2*V1-2*V2-2*V3+V4*3 && v[1]==V1+V2+V3-V4*3 && v[2]==V4){
            cout << "Yes" << endl;
            cout << 0 << " " << 0 << " " << 0 << " " << b1 << " " << b2 << " " << b3 << " " << c1 << " " << c2 << " " << c3 << endl;
            return 0;
        }
        //cout << V1 << " " << V2 << " " << V3 << " " << V4 << endl;
    }
    cout << "No" << endl;
}
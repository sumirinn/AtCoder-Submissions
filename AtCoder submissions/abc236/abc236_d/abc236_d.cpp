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

int n, n2;
vector<vector<int>> a;
int ans;

void dfs(vector<bool> s, int x) {
    int si = -1;
    rep(i,n2) if(!s[i]){
        si = i;
        break;
    }
    if(si==-1){
        ans = max(ans, x);
        return;
    }

    s[si] = true;
    rep(i,n2)if(!s[i] && si!=i){
        s[i] = true;
        dfs(s, x^a[si][i]);
        s[i] = false;
    }
};

int main(){
    cin >> n;
    n2 = n*2;
    a = vector<vector<int>>(n2, vector<int>(n2));
    rep(i,n2){
        for(int j=i+1; j<n2; j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    vector<bool> s(n2);
    dfs(s, 0);
    cout << ans << endl;
}
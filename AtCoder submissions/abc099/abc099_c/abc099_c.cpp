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
    int n;
    cin >> n;

    vector<int> m(n+1, 0);
    
    auto f = [&](auto f, int k) -> int{
        if(k==0) return 0;
        if(m[k]) return m[k];

        int res = inf;
        chmin(res, f(f, k-1) + 1);

        int x = 6;
        while(x<=k){
            chmin(res, f(f, k-x)+1);
            x *= 6;
        }

        int y = 9;
        while(y<=k){
            chmin(res, f(f, k-y)+1);
            y *= 9;
        }

        m[k] = res;
        return res;
    };

    cout << f(f, n) << endl;
}
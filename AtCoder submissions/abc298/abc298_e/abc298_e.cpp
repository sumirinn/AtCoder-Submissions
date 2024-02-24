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

mint mem[101][101][2];
bool  visited[101][101][2];

int main(){
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    mint ip = mint(1)/p;
    mint iq = mint(1)/q;

    auto f = [&](auto f, int a, int b, int t) -> mint{
        if(a>=n) return 1;
        if(b>=n) return 0;
        if(visited[a][b][t]) return mem[a][b][t];
        mint res;
        if(t==0){
            for(int i=1; i<=p; i++){
                res += f(f, a+i, b, 1);
            }
            res *= ip;
        }
        if(t==1){
            for(int i=1; i<=q; i++){
                res += f(f, a, b+i, 0);
            }
            res *= iq;
        }
        visited[a][b][t] = true;
        return mem[a][b][t] = res;
    };

    cout << f(f, a, b, 0).val() << endl;
}
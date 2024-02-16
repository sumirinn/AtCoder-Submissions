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
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m;
    cin >> n >> m;

    vector<P> d;
    for(int i=-n; i<n; i++)for(int j=-n; j<n; j++)if(i*i+j*j==m) d.emplace_back(i, j);

    vector<vector<int>> dist(n, vector<int>(n, -1));
    //dist[0][0] = 0;

    queue<P> q;
    //q.push(make_pair(0, 0));

    auto push = [&](int i, int j, int D){
        if(i<0 || j<0 || i>=n || j>=n) return;
        if(dist[i][j]!=-1) return;
        dist[i][j] = D;
        q.emplace(i, j);
    };
    push(0, 0, 0);

    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(auto[di, dj] : d){
            int ni = i + di, nj = j + dj;
            push(ni, nj, dist[i][j]+1);
        }
    }

    rep(i, n){
        rep(j, n) cout << dist[i][j] << " ";
        cout << endl;
    }
}
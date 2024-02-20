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
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


struct Weighed_UnionFind {
    vector<int> p;
    vector<ll> dif;
    Weighed_UnionFind(int n): p(n, -1), dif(n) {}

    int root(int a){
        if(p[a]<0) return a;
        int b = p[a];
        p[a] = root(b);
        dif[a] += dif[b];
        return p[a];
    }

    bool merge(int a, int b, ll w){
        root(a); root(b);
        w = w + dif[a] - dif[b];
        a = root(a); b = root(b);
        if(a==b) return w==0;
        if(-p[a]<-p[b]) swap(a, b), w = -w;
        p[a] += p[b];
        p[b] = a; dif[b] = w;
        return true;
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> ans;
    Weighed_UnionFind uf(n);

    rep(qi, q){
        int a, b;
        ll d;
        cin >> a >> b >> d;
        a--; b--;
        if(uf.merge(a, b, d)) ans.push_back(qi+1);
    }

    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}
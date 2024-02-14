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
//97~122(a~z),65~90(A~Z)

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    set<P> s;
    map<P, int> m;
    dsu uf(n);
    rep(i, n){
        cin >> x[i] >> y[i];
        s.emplace(x[i], y[i]);
        m[make_pair(x[i], y[i])] = i;
    }

    int dx[] = {0, 1, 1, 0, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, 0};

    rep(i, n){
        int a = x[i], b = y[i];
        rep(u, 6){
            P npos = make_pair(a+dx[u],b+dy[u]);
            if(s.count(npos)){
                int nex = m[npos];
                uf.merge(i, nex);
            }
        }
    }

    set<int> t;
    rep(i, n)if(!t.count(uf.leader(i))) t.insert(uf.leader(i));
    cout << t.size() << endl; 
}
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n, m; cin >> n >> m;
    dsu uf(n);
    repp(i,m){
        int a, b; cin >> a >> b; a--; b--;
        uf.merge(a, b);
    }

    int k; cin >> k;
    set<P> st;
    rep(i, k){
        int a, b; cin >> a >> b; a--; b--;
        a = uf.leader(a);
        b = uf.leader(b);
        if(a>b) swap(a, b);
        st.emplace(a, b);
    }
    
    int q; cin >> q;
    rep(i, q){
        int a,b; cin >> a >> b; a--; b--;
        a = uf.leader(a);
        b = uf.leader(b);
        if(a>b) swap(a, b);
        if(st.count(P(a, b))) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
}
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
ll c3(ll n) { return n*(n-1)*(n-2) / 6; }
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int n = h*w;
    dsu uf(n);
    auto toID = [&](int i, int j){return i*w+j;};
    rep(i, h)rep(j, w){
        if(s[i][j]!='.') continue;
        if(j+1<w && s[i][j+1]=='.') uf.merge(toID(i, j), toID(i, j+1));
        if(i+1<h && s[i+1][j]=='.') uf.merge(toID(i, j), toID(i+1, j));
    }

    rep(i, h)rep(j, w)if(s[i][j]=='S'){
        set<int> st;
        int cnt = 0;
        rep(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
            if(s[ni][nj]!='.') continue;
            st.insert(uf.leader(toID(ni, nj)));
            cnt++;
        }
        if(st.size()==cnt) cout << "No" << endl;
        else cout << "Yes" << endl; 
    }
}
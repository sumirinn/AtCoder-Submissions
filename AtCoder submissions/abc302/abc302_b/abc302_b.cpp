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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    string T = "snuke";
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    rep(si, h)rep(sj, w){
        rep(v, 8){
            int i = si, j = sj;
            rep(k, 5){
                if(i<0 || j<0 || i>=h || j>=w) break;
                if(s[i][j]!=T[k]) break;
                if(k==4){
                    i = si, j = sj;
                    rep(nk, 5){
                        cout << i+1 << " " << j+1 << endl;
                        i += dx[v], j += dy[v];
                    }
                    return 0;
                }
                i += dx[v]; j += dy[v];
            }
        }
    }
}
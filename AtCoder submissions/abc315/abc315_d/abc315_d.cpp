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
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h)rep(j, w) a[i][j] = c[i][j] - 'a';

    const int m = 26;
    vector<vector<int>> row(h, vector<int>(m));
    vector<vector<int>> col(w, vector<int>(m));
    rep(i, h)rep(j, w){
        row[i][a[i][j]]++;
        col[j][a[i][j]]++;
    }
    vector<bool> row_deleted(h);
    vector<bool> col_deleted(w);

    auto toDelete = [&](vector<int> x) -> bool {
        int tot = 0, k = 0;
        rep(i, m){
            tot += x[i];
            if(x[i]) k++;
        }
        return tot>=2 && k==1;
    };

    auto del = [&](int i, int j) {
        if(row_deleted[i] || col_deleted[j]) return;
        row[i][a[i][j]]--;
        col[j][a[i][j]]--; 
    };

    bool upd = true;
    while(upd){
        upd = false;
        vector<int> del_row, del_col;

        rep(i, h){
            if(row_deleted[i]) continue;
            if(toDelete(row[i])) del_row.push_back(i);
        }

        rep(j, w){
            if(col_deleted[j]) continue;
            if(toDelete(col[j])) del_col.push_back(j);
        }

        for(int i : del_row){
            rep(j, w) del(i, j);
            row_deleted[i] = true;
            upd = true;
        }

        for(int j : del_col){
            rep(i, h) del(i, j);
            col_deleted[j] = true;
            upd = true;
        }
    }

    int ans = 0;
    rep(i, h)rep(j, w){
        if(row_deleted[i] || col_deleted[j]) continue;
        ans++;
    }

    cout << ans << endl;
}
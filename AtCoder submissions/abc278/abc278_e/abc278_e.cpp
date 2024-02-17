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
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
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
    int h, w, n, H, W;
    cin >> h >> w >> n >> H >> W;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];

    map<int, int> mp;
    set<int> st;
    rep(i, h)rep(j, w){
        mp[a[i][j]]++;
        st.insert(a[i][j]);
    }

    rep(i, H)rep(j, W){
        mp[a[i][j]]--;
        if(mp[a[i][j]]==0) st.erase(a[i][j]);
    }

    rep(i, h-H+1){
        map<int, int> mp;
        set<int> st;
        rep(u, h)rep(v, w){
            mp[a[u][v]]++;
            st.insert(a[u][v]);
        }

        rep(u, H)rep(v, W){
            mp[a[u+i][v]]--;
            if(mp[a[u+i][v]]==0) st.erase(a[u+i][v]);
        }
        cout << st.size() << " ";

        rep(j, w-W){
            rep(u, H){
                mp[a[i+u][j]]++;
                st.insert(a[i+u][j]);
                mp[a[i+u][j+W]]--;
                if(mp[a[i+u][j+W]]==0) st.erase(a[i+u][j+W]);
            }
            cout << st.size() << " ";
        }
        cout << endl;
    }

}
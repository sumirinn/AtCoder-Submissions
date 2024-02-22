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
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)


int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<P> a(n), b(n), c(n);
    rep(i, n) cin >> a[i].first, a[i].second = i;
    rep(i, n) cin >> b[i].first, b[i].second = i;
    rep(i, n) c[i].first = a[i].first + b[i].first, c[i].second = i;


    set<int> st;
    rep(j, x){
        int m = -1;
        rep(i, n) m = max(m, a[i].first);
        bool ok = true;
        rep(i, n){
            if(!ok) continue;
            if(m==a[i].first){
                st.insert(a[i].second);
                ok = false;
                a[i].first = -1;
            }
        }
    }

    while(y>0){
        int m = -1;
        rep(i, n) m = max(m, b[i].first);
        bool ok = true;
        rep(i, n){
            if(!ok) continue;
            if(m==b[i].first){
                b[i].first = -1;
                ok = false;
                if(!st.count(b[i].second)){
                    st.insert(b[i].second);
                    y--;
                }
            }
        }
    }

    while(z>0){
        int m = -1;
        rep(i, n) m = max(m, c[i].first);
        bool ok = true;
        rep(i, n){
            if(!ok) continue;
            if(m==c[i].first){
                c[i].first = -1;
                ok = false;
                if(!st.count(c[i].second)){
                    st.insert(c[i].second);
                    z--;
                }
            }
        }
    }

    for(int i : st) cout << i + 1 << endl;
}
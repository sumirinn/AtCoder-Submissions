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
using MP = map<int, vector<int>>;
using mint = modint998244353;
using P = pair<ll, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
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
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    set<string> st;
    rep(i,n) cin >> S[i];
    rep(i,m){
        string t;
        cin >> t;
        st.insert(t);
    }
    int max_u = 16 - (n-1);
    rep(i, n) max_u -= S[i].size();

    vector<bool> used(n);
    auto dfs = [&](auto f, int i, string s, int u){
        if(i==n){
            if(s.size()<3) return false;
            if(st.count(s)) return false;
            cout << s << endl;
            return true;
        }
        if(u){
            if(f(f, i, s+ '_', u-1)) return true;
        }
        rep(j,n)if(!used[j]){
            used[j] = true;
            if(f(f, i+1, s+'_'+S[j], u)) return true;
            used[j] = false;
        }
        return false;
    };

    rep(i,n){
        used[i] = true;
        if(dfs(dfs, 1, S[i], max_u)) return 0;
        used[i] = false;
    }
    cout << -1 << endl;
}
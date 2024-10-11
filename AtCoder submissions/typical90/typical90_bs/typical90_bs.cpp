#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> to(n);
    vector<int> deg(n);
    rep(mi,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].pb(v);
        deg[v]++;
    }

    vector<int> st;
    vector<int> p(n,-1);
    vector<vector<int>> answers;
    auto dfs =[&](auto dfs, int dep)->bool{
        if(dep==n){
            answers.pb(p);
            return true;
        }
        if(st.empty()) return false;
        for(int i=st.size()-1; i>=0; i--){
            if(answers.size()==k) break;
            int x = st[i];
            st.erase(st.begin()+i);
            for(int j : to[x]){
                deg[j]--;
                if(deg[j]==0) st.pb(j);
            }
            p[dep] = x;
            bool sign = dfs(dfs,dep+1);
            if(!sign) return false;
            for(int j : to[x]){
                if(deg[j]==0) st.pop_back();
                deg[j]++;
            }
            st.insert(st.begin()+i, x);
        }
        return true;
    };
    rep(i,n)if(deg[i]==0) st.pb(i);
    dfs(dfs,0);

    if(answers.size()!=k) cout << -1 << endl;
    else{
        for(auto ans : answers){
            for(int v : ans) cout << v + 1 << " ";
            cout << endl;
        }
    } 
}
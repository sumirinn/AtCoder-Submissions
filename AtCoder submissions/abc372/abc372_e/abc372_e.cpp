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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    map<int,set<int>> mp;
    rep(i,n) mp[i].insert(i);
    vector<int> answers;

    rep(qi,q){
        int type;
        cin >> type;
        if(type==1){
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(uf.same(u,v)) continue;
            int lu=uf.leader(u), lv=uf.leader(v);
            set<int> nex;
            rep(cnt,10){
                if(mp[lu].empty() && mp[lv].empty()) break;
                int fu=-1, fv=-1;
                if(!mp[lu].empty()) fu=*mp[lu].rbegin(); 
                if(!mp[lv].empty()) fv=*mp[lv].rbegin(); 
                if(fu<fv){
                    nex.insert(fv);
                    mp[lv].erase(fv);
                }
                else{
                    nex.insert(fu);
                    mp[lu].erase(fu);
                }
            }

            uf.merge(u,v);
            int p = uf.leader(u);
            mp[p] = nex;
        }
        if(type==2){
            int v, k;
            cin >> v >> k;
            v--;
            int lv = uf.leader(v);
            int ans = -2;
            for(auto it=mp[lv].rbegin(); it!=mp[lv].rend(); ++it){
                k--;
                if(k==0) ans = *it;
            }

            answers.pb(ans + 1);
        }
    }

    for(int ans : answers) cout << ans << endl;
}
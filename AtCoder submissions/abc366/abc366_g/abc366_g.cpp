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
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct Matrix {
    using BS = bitset<61>;
    int h, w;
    vector<BS> d;
    Matrix(int h, int w): h(h), w(w), d(h) {}
    BS operator[](int i) const {return d[i];}
    BS& operator[](int i) {return d[i];}
    BS solve(){
        int ni = 0;
        rep(j,w-1){
            for(int i=ni; i<h; i++){
                if(d[i][j]){
                    swap(d[i],d[ni]);
                    break;
                }
            }
            if(!d[ni][j]) continue;
            rep(i,h) if(ni!=i && d[i][j]) d[i] ^= d[ni];
            ni++;
            if(ni==h) break;
        }
        BS no, res;
        no[w-1] = 1;
        rep(i,h){
            int j = 0;
            while(j<w-1 && !d[i][j]) j++;
            if(j==w-1){
                if(d[i][w-1]) return no;
                continue;
            }
            res[j] = d[i][w-1];
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    Matrix d(n+1,n+1);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        d[u][v] = 1;
        d[v][u] = 1;
    }

    vector<ll> ans(n); 
    rep(i,n){
        Matrix nd = d;
        nd[n][i] = 1;
        nd[n][n] = 1;
        auto sol = nd.solve();
        if(sol[n]){
            cout << "No" << endl;
            return 0;
        }
        rep(j,n)if(sol[j]) ans[j] |= 1ll<<i;
    }

    cout << "Yes" << endl;
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
}
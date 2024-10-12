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
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<char>> b(n,vector<char>(n,'a'));
    rep(s,n/2){
        int ri = (s+1) % 4;
        if(ri==0){
            for(int i=s; i<=n-1-s; i++){
                b[i][s] = a[i][s];
                b[i][n-1-s] = a[i][n-1-s];
            }
            for(int j=s; j<=n-1-s; j++){
                b[s][j] = a[s][j];
                b[n-1-s][j] = a[n-1-s][j];
            }
        }
        if(ri==1){
            for(int i=s; i<=n-1-s; i++){
                b[s][n-1-i] = a[i][s];
                b[n-1-s][n-1-i] = a[i][n-1-s];
            }
            for(int j=s; j<=n-1-s; j++){
                b[j][n-1-s] = a[s][j];
                b[j][s] = a[n-1-s][j];
            }
        }
        if(ri==2){
            for(int i=s; i<=n-1-s; i++){
                b[i][s] = a[n-1-i][n-1-s];
                b[i][n-1-s] = a[n-1-i][s];
            }
            for(int j=s; j<=n-1-s; j++){
                b[s][n-1-j] = a[n-1-s][j];
                b[n-1-s][j] = a[s][n-1-j];
            }
        }
        if(ri==3){
            for(int i=s; i<=n-1-s; i++){
                b[n-1-s][i] = a[i][s];
                b[s][i] = a[i][n-1-s];
            }
            for(int j=s; j<=n-1-s; j++){
                b[n-1-j][s] = a[s][j];
                b[n-1-j][n-1-s] = a[n-1-s][j];
            }
        }
    }

    rep(i,n){
        rep(j,n) cout << b[i][j];
        cout << endl;
    }
}

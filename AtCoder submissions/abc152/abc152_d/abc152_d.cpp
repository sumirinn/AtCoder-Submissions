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
    int n;
    cin >> n;

    const int m = 10;
    vector<vector<ll>> cnt(m,vector<ll>(m,0));
    //vector<vector<ll>> cnt2(m,vector<ll>(m,0));

    repp(i,n){
        int f = i % 10;
        int g = 0;
        int j = i;
        while(j!=0){
            g = j %10;
            j /= 10;
        }
        cnt[f][g]++;
        //cout << f << " " << g << endl;
    }

    ll ans = 0;
    rep(i,m)rep(j,m){
        if(i==0 || j==0 || i== j) continue;
        ans += cnt[i][j]*cnt[j][i];
        //cout << i << " " << j << " " << cnt[i][j]*cnt[j][i] << endl;
    }
    rep(i,m) ans += cnt[i][i]*cnt[i][i];
    cout << ans << endl;
}
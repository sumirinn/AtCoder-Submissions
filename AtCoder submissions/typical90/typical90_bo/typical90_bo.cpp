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
    string n;
    int k;
    cin >> n >> k;
    int m = n.size();
    vector<ll> p8(m);
    p8[0] = 1;
    rep(i,m-1) p8[i+1] = p8[i]*8;

    reverse(n.begin(),n.end());
    rep(ki,k){
        ll now = 0;
        rep(i,m) now += int(n[i] - '0')*p8[i];
        rep(i,m){
            n[i] = char(now%9 + '0');
            now /= 9;
        }
        rep(i,m)if(n[i]=='8') n[i] = '5';
    }

    reverse(n.begin(),n.end());
    bool ok = false;
    rep(i,m){
        if(n[i]!='0') ok = true;
        if(ok) cout << n[i];
    }
    if(ok==false) cout << 0;
    cout << endl;
}
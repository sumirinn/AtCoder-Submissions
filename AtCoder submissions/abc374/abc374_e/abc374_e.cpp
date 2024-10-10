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


struct Machine{
    int a, p;
};

int main(){
    int n, x;
    cin >> n >> x;
    vector<Machine> s(n), t(n);
    rep(i,n){
        cin >> s[i].a >> s[i].p;
        cin >> t[i].a >> t[i].p;
        if(t[i].a * s[i].p > s[i].a * t[i].p){
            swap(s[i],t[i]);
        }
    }

    auto f =[&](int m){
        ll cost = 0;
        rep(i,n){
            ll now = INF;
            rep(j,s[i].a){
                int k = max(m-t[i].a*j, 0);
                k = (k+s[i].a-1) / (ll)s[i].a;
                now = min(now, t[i].p*j + (ll)s[i].p*k);
            }
            cost += now;
            if(cost>x) return false;
        }
        return true;
    };

    int ac=0, wa=x*100+1;
    while(ac+1<wa){
        int wj = (ac+wa) / 2;
        if(f(wj)) ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
}
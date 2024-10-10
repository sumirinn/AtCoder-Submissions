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

int n;
int idx[1609];
int fib[16] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };


int ask(int pos){
    if(idx[pos]==-1){
        cout << "? " << pos << endl;
        int t;
        cin >> t;
        idx[pos] = t;
    }
    return idx[pos];
}


void solve(){
    cin >> n;
    int ans = 0;
    rep(i,n+1) idx[i] = -1;
    for(int i=n+1; i<=1600; i++) idx[i] = -i;

    if(n<=5) repp(i,n) ans = max(ans,ask(i));
    else{
        int cl=0, cr=1597, dl=610, dr=987;
        int el = ask(dl);
        int er = ask(dr);
        ans = max({ans,el,er});
        if(el<er){
            cl = dl;
            dl = dr;
            dr = -1;
            el = er;
            er = -1;
        }
        else{
            cr = dr;
            dr = dl;
            dl = -1;
            er = el;
            el = -1;
        }

        for(int i=12; i>=0; i--){
            if(dl==-1){
                dl = cl + fib[i];
                el = ask(dl);
            }
            else if(dr==-1){
                dr = cr - fib[i];
                er = ask(dr);
            }
            ans = max({ans,el,er});
            if(el<er){
                cl = dl;
                dl = dr;
                dr = -1;
                el = er;
                er = -1;
            }
            else{
                cr = dr;
                dr = dl;
                dl = -1;
                er = el;
                el = -1;
            }
        }
        for(int i=cl+1; i<=cr-1; i++){
            ans = max(ans,ask(i));
        }
    }
    cout << "! " << ans << endl;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
}
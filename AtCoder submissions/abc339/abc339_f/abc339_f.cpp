#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using MP = map<int, vector<int>>;
using mint = modint998244353;
//using mint = modint1000000007;
using P = pair<int , int>;
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
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
//auto nex = calc_next で取得すると楽。
vector<vector<int> > calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int> > res(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
//comb(n,k)でnCkになる。
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*n), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*invs(n)), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
}
//97~122(a~z),65~90(A~Z)


const int S = 10;
const int M = 1e9;

bool isPrime(int x){
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}

int mult(int a, int b, int p){
    return (ll)a*b%p;
}

int main(){
    vector<int> ps;
    while(ps.size()<S){
        int p = rand()%M;
        if(!isPrime(p)) continue;
        ps.push_back(p);
    }

    int n;
    cin >> n;
    vector<vector<int>> xs(n);
    rep(i,n){
        string a;
        cin >> a;
        for(int p : ps){
            ll x = 0;
            for(char c : a){
                x = (x*10 + (c-'0'))%p;
            }
            xs[i].push_back(x);
        }
    }

    map<vector<int>, int> cnt;
    rep(i,n) cnt[xs[i]]++;

    int ans = 0;
    rep(i,n)rep(j,n){
        vector<int> cs;
        rep(k,S){
            cs.push_back(mult(xs[i][k],xs[j][k], ps[k]));
        }
        ans += cnt[cs];
    }

    cout << ans << endl;
}
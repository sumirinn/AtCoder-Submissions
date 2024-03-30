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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using MP = map<int, vector<int>>;
using mint = modint998244353;
//using mint = modint1000000007;
using P = pair<double , double>;
void chmax(double& x, double y) {x = max(x, y);} // change max
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
//素数判定  
bool isPrime(int x){
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}
// Geometry
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}
//vector
struct V {
    double x, y;
    V(double x=0, double y=0): x(x), y(y) {}
    V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
    V operator+(const V& v) const { return V(*this) += v;}
    V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
    V operator-(const V& v) const { return V(*this) -= v;}
    V& operator*=(double s) { x *= s; y *= s; return *this;}
    V operator*(double s) const { return V(*this) *= s;}
    V& operator/=(double s) { x /= s; y /= s; return *this;}
    V operator/(double s) const { return V(*this) /= s;}
    double dot(const V& v) const { return x*v.x + y*v.y;}
    double cross(const V& v) const { return x*v.y - v.x*y;}
    double norm2() const { return x*x + y*y;}
    double norm() const { return sqrt(norm2());}
    V normalize() const { return *this/norm();}
    V rotate90() const { return V(y, -x);}
    int ort() const { // orthant
        if (abs(x) < eps && abs(y) < eps) return 0;
        if (y > 0) return x>0 ? 1 : 2;
        else return x>0 ? 4 : 3;
    }
    bool operator<(const V& v) const {
        int o = ort(), vo = v.ort();
        if (o != vo) return o < vo;
        return cross(v) > 0;
    }
};
istream& operator>>(istream& is, V& v) {
    is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
    os<<"("<<v.x<<","<<v.y<<")"; return os;
}
//97~122(a~z),65~90(A~Z)

double op(double a, double b){return min(a, b);}
double e() {return 1e18;}

int main(){
    int n, k;
    cin >> n >> k;
    V s;
    cin >> s;
    vector<V> ps(n);
    rep(i,n) cin >> ps[i];

    double base = 0;
    base += (ps[0]-s).norm();
    base += (ps[n-1]-s).norm();
    vector<double> d = {0};
    rep(i,n-1){
        double dist = (ps[i+1]-ps[i]).norm();
        base += dist;
        double dist2 = (ps[i+1]-s).norm() + (ps[i]-s).norm();
        d.push_back(dist2-dist);
    }
    d.push_back(0);

    segtree<double, op, e> t(n+1);
    t.set(0, 0);
    repp(i,n){
        int l = max(i-k, 0);
        double now = t.prod(l,i) + d[i];
        t.set(i,now);
    }

    double ans = base + t.get(n);
    cout << fixed << setprecision(20) << ans << endl;
}
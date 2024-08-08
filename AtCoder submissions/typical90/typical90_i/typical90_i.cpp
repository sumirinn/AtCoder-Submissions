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



struct Point{
    double px, py;
};

Point operator-(const Point& a1, const Point& a2){
    return Point{a1.px-a2.px, a1.py-a2.py};
}

double getangle(Point G) { 
	double I = G.px / sqrt(G.px * G.px + G.py * G.py);
	double arg = acos(I) * 180.0 / 3.14159265358979;
	if(G.py >= 0.0) return arg;
	else return 360.0 - arg;
}

double getangle2(double I1, double I2) {
	double res = abs(I1 - I2);
	if (res >= 180.0) return 360.0 - res;
	return res;
}

int main(){
    int n;
    cin >> n;
    vector<Point> r(n);
    rep(i,n) cin >> r[i].px >> r[i].py;

    double ans = 0;
    rep(i,n){
        vector<double> args;
        rep(j,n){
            if(i==j) continue;
            Point SA = r[i] - r[j];
            double arg = getangle(SA);
            args.pb(arg);
        }
        sort(args.begin(), args.end());
        
        double res = 0;
        for(double arg : args){
            double tgt = arg + 180;
            if(tgt>=360) tgt -= 360;
            int pos = lower_bound(args.begin(),args.end(),tgt) - args.begin();
            int pos1 = pos%args.size();
            int pos2 = (pos + args.size() - 1) % args.size();
            double arg1 = getangle2(arg, args[pos1]);
            double arg2 = getangle2(arg, args[pos2]);
            res = max({res, arg1, arg2});
        }
        ans = max(ans,res);
    }

    cout << fixed << setprecision(10) << ans << endl;
}
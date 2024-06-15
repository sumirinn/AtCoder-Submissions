#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w;
    cin >> h >> w;
    int n = h*w;
    dsu uf(n);
    vector<vector<bool>> s(h, vector<bool>(w,false));

    int q;
    cin >> q;
    rep(qi,q){
        int t;
        cin >> t;
        if(t==1){
            int i, j;
            cin >> i >> j;
            i--; j--;
            s[i][j] = true;
            rep(v,4){
                int ni=i+di[v], nj=j+dj[v];
                if(ni<0||nj<0||ni>=h||nj>=w) continue;
                if(s[ni][nj]) uf.merge(i*w+j,ni*w+nj);
            }
        }
        if(t==2){
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            if(uf.same(ra*w+ca,rb*w+cb) && s[ra][ca] && s[rb][cb]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
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
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    auto id =[&](int i, int j){return i*m+j;};
    int nm = n*m;
    mf_graph<int> mf(nm+2);
    int st=nm, gl=nm+1;
    rep(i,n)rep(j,m){
        if(s[i][j]=='#') continue;
        if((i+j)%2==0){
            mf.add_edge(st,id(i,j),1);
            rep(v,4){
                int ni=i+di[v], nj=j+dj[v];
                if(ni<0||nj<0||ni>=n||nj>=m) continue;
                if(s[ni][nj]=='#') continue;
                mf.add_edge(id(i,j),id(ni,nj),1);
            }
        }
        if((i+j)%2==1) mf.add_edge(id(i,j),gl,1);
    }
    
    int mx = mf.flow(st,gl);
    cout << mx << endl;
    for(auto e : mf.edges()){
        if(e.flow==0) continue;
        if(e.from==st) continue;
        if(e.to==gl) continue;
        int ifro=e.from/m, jfro=e.from%m;
        int ito=e.to/m, jto=e.to%m;
        if(ifro==ito){
            if(jfro>jto) swap(jfro,jto);
            s[ifro][jfro] = '>';
            s[ito][jto] = '<';
        }
        if(jfro==jto){
            if(ifro>ito) swap(ifro,ito);
            s[ifro][jfro] = 'v';
            s[ito][jto] = '^';
        }
    }

    rep(i,n) cout << s[i] << endl;
}
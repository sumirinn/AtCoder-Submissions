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
#define mp make_pair
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
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y; cin >> x >> y;
    return C(x,y);
}
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)


int main(){
    int n;
    cin >> n;
    if(n==0){
        cout << "#" << endl;
        return 0;
    }
    int n3 = 1;
    rep(i,n) n3 = n3*3;
    vector<int> p3(n);
    p3[0] = 1;
    rep(i,n-1) p3[i+1] = p3[i]*3;
    vector<vector<char>> s(n3,vector<char>(n3));

    auto f = [&](auto f, int siz, int a, int b) ->void{
        if(siz==1){
            rep(i,3)rep(j,3){
                if(i==1&&j==1) s[a+i][b+1] = '.';
                else s[a+i][b+j] = '#';
            }
        }
        else{
            rep(i,3)rep(j,3){
                if(i==1&&j==1){
                    for(int u=a+p3[siz-1]; u<a+p3[siz-1]*2; u++){
                        for(int v=b+p3[siz-1]; v<b+p3[siz-1]*2; v++){
                            s[u][v] = '.';
                        }
                    }
                }
                else f(f,siz-1,a+p3[siz-1]*i,b+p3[siz-1]*j);
            }
        }
    };
    f(f,n,0,0);
    rep(i,n3){
        rep(j,n3){
            cout << s[i][j];
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
//#define int long long
//typedef long long int;
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  
using pdd = pair<double, double>; using pli = pair<ll, int>;
using pil = pair<int, ll>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる。
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<ll, int>;
using MP = map<int, vector<int>>;
using C = complex<double>;
C inC(){
    double x, y;
    cin >> x >> y;
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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int ans = 0;
    rep(r,2){
        vector<int> visited(n*n);
        vector<int> dist(n*n, inf);
        deque<int> q;
        char c;
        if(r==0){
            q.push_back(0);
            dist[0] = 0;
            c = 'R';
        }
        if(r==1){
            q.push_back(n-1);
            dist[n-1] = 0;
            c = 'B';
        }
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            int i = v/n;
            int j = v%n;
            rep(d,4){
                int ni=i+di[d], nj=j+dj[d];
                if(ni<0||nj<0||ni>=n||nj>=n) continue;
                int D = 0;
                if(s[ni][nj]!=c) D = 1;
                int dis = dist[i*n+j] + D;
                if(dis<dist[ni*n+nj]){
                    dist[ni*n+nj] = dis;
                    if(D==0) q.push_front(ni*n+nj);
                    else q.push_back(ni*n+nj);
                }
            }
        }

        if(r==0) ans += dist[n*n-1];
        if(r==1) ans += dist[n*(n-1)];
    }

    cout << ans << endl;
}
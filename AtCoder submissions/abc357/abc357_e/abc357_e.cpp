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
    vector<vector<int>> to(n);
    vector<vector<int>> tob(n);
    dsu uf(n);
    int st = 0;
    ll ans = 0;
    rep(i,n){
        int u;
        cin >> u;
        u--;
        if(i==u && st==i)  st++;
        to[i].push_back(u);
        tob[u].push_back(i);
        uf.merge(i,u);
    }

    vector<bool> visited(n,false), on(n), start(n);
    vector<int> cy(n);
    rep(st,n){
        int pos = uf.leader(st);
        if(start[pos]) continue;
        start[pos] = true;
        int ncc = 0;
        while(!visited[pos]){
            visited[pos] = true;
            cy[pos] = ncc;
            pos = to[pos][0];
            ncc++;
        }
        set<int> S;
        int posc = to[pos][0];
        S.insert(pos);
        while(posc!=pos){
            S.insert(posc);
            posc = to[posc][0];
        }

        //cout << ncc << " " << cy[pos] << endl;
        ll cnt = ncc - cy[pos];
        //cout << cnt << endl;
        ans += cnt*cnt;
        int i = pos;
        while(true){
            int nc = cnt;
            auto f=[&](auto f,int v, ll c,int C)->void{
                if(C!=0) ans += c;
                for(int u : tob[v]){
                    if(S.count(u)) continue;                        
                    f(f,u,c+1,1);
                }
            };
            f(f,i,nc,0);
            i = to[i][0];
            if(i==pos) break;
        }
    }
    cout << ans << endl;
}
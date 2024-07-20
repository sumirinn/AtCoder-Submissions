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
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<int, pii>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<bool> sd(h*w);
    vector<bool> fd(h*w);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    rep(i,h){
        q.push(pii(a[i][0],i*w+0));
        q.push(pii(a[i][w-1],i*w+w-1));
        fd[i*w+0]=true;
        fd[i*w+w-1]=true;
    }
    rep(j,w){
        q.push(pii(a[0][j],0*w+j));
        q.push(pii(a[h-1][j],(h-1)*w+j));
        fd[0*w+j]=true;
        fd[(h-1)*w+j]=true;
    }

    int ans = h*w;
    repp(i,y){
        while(!q.empty() && q.top().fi<=i){
            auto now = q.top();
            q.pop();
            if(sd[now.se]) continue;
            sd[now.se]=true;
            ans--;
            rep(v,4){
                int ni=now.se/w + di[v];
                int nj=now.se%w + dj[v];
                if(ni<0||nj<0||ni>=h||nj>=w) continue;
                if(fd[ni*w+nj]) continue;
                if(sd[ni*w+nj]) continue;

                q.push(pii(a[ni][nj],ni*w+nj));
                fd[ni*w+nj]=true;
            }
        }

        cout << ans << endl;
    }
}
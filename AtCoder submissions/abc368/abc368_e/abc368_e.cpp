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
//using P = pair<double, int>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


struct Train{
    int a, b, s, t, i;
    Train(int a, int b, int s, int t, int i): a(a), b(b), s(s), t(t), i(i) {}
    bool operator<(const Train& x) const{
        return s < x.s;
    }
};

int main(){
    int n, m, x1;
    cin >> n >> m >> x1;

    vector<Train> trains;
    rep(i,m){
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a--; b--;
        trains.eb(a,b,s,t,i);
    }
    sort(trains.begin(),trains.end());

    vector<int> x(m);
    vector<int> maxT(n);
    vector<priority_queue<pii,vector<pii>,greater<pii>>> q(n);
    for(auto [a,b,s,t,i] : trains){
        if(i==0) x[i] = x1;
        else{
            while(!q[a].empty()){
                auto [nt,val] = q[a].top();
                if(nt>s) break;
                q[a].pop();
                maxT[a] = max(maxT[a],val);
            }
            x[i] = max(0,maxT[a]-s);
        }
        q[b].emplace(t,t+x[i]);
    }

    rep(i,m) if(i) cout << x[i] << " ";
    cout << endl;
}
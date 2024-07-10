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

// Convex Hull Trick (min)
struct CHT {
    //直線を表すstruct
    struct Linear {
        ll a, b;
        Linear(ll a=0, ll b=0): a(a), b(b) {}
        ll operator()(ll x) const { return a*x+b;}
    };

    //傾きが小→大になるように直線を保持
    deque<Linear> ls;

    //直線が必要でなければ消す関数
    //aの降順sortをしてから
    void add(ll a, ll b) {
        Linear l(a,b);
        while (ls.size() >= 2) {
            //前二つを取ってくる
            const Linear& l1 = ls[0];
            const Linear& l2 = ls[1];
            //その2直線と今追加しようとしている直線の交わり方が良ければ、
            //whileをbreakしてlを追加
            if ((l2.a-l.a)*(l.b-l1.b) > (l1.a-l.a)*(l.b-l2.b)) break;
            ls.pop_front();
        }
        ls.push_front(l);
    }

    //xの値を返す関数
    //xの昇順sortが必要
    ll operator()(ll x) { // x: asc
        ll res = ls.back()(x);
        while (ls.size() >= 2) {
            ll now = ls[ls.size()-2](x);
            if (now > res) break;
            res = now;
            ls.pop_back();
        }
        return res;
    }
};

int main(){
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    vector<ll> dp(n);
    dp[0] = 0;
    CHT cht;
    cht.add(-2*h[0], h[0]*h[0]);

    rep(i,n){
        if(i==0) continue;
        dp[i] = cht(h[i]) + h[i]*h[i] + c;
        cht.add(-2*h[i], h[i]*h[i]+dp[i]);
    }

    cout << dp[n-1] << endl;
}
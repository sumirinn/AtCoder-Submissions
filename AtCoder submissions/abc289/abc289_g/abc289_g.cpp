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

// Convex Hull Trick (max)
// https://youtu.be/TSvXG35mmRE?t=7853
struct CHT {
    //直線を表すstruct
    struct Linear {
        ll a, b;
        Linear(ll a=0, ll b=0): a(a), b(b) {}
        ll operator()(ll x) const { return a*x+b;}
    };
    deque<Linear> ls;
    //直線が必要でなければ消す関数
    void add(ll a, ll b) {
        Linear l(a,b);
        //assertは、もし条件が偽であれば、プログラムの実行を中断し、エラーメッセージを表示する。
        assert(ls.size() == 0 || ls.back().a <= l.a);
        while (ls.size() >= 2) {
            //後ろ二つを取ってくる
            const Linear& l1 = ls[ls.size()-2];
            const Linear& l2 = ls.back();
            //その2直線と今追加しようとしている直線の交わり方が良ければ、
            //whileをbreakしてlを追加
            if ((l.a-l2.a)*(l1.b-l2.b) < (l2.a-l1.a)*(l2.b-l.b)) break;
            ls.pop_back();
        }
        ls.push_back(l);
    }
    //xの値を返す関数
    ll operator()(ll x) { // x: asc
        ll res = ls[0](x);
        while (ls.size() >= 2) {
            ll now = ls[1](x);
            if (now < res) break;
            res = now;
            ls.pop_front();
        }
        return res;
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    vector<pii> cs(m);
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> cs[i].fi;
    rep(i,m) cs[i].se = i;
    sort(b.begin(),b.end());
    sort(cs.begin(),cs.end());

    CHT cht;
    rep(i,n) cht.add(i+1,b[n-i-1]*ll(i+1));
    vector<ll> ans(m);
    for(auto [c,i] : cs){
        ans[i] = cht(c);
    }

    rep(i,m) cout << ans[i] << " ";
    cout << endl;
}
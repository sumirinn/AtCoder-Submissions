#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using MP = map<int, vector<int>>;
using mint = modint998244353;
//using P = pair<ll, ll>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int & x, int y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

struct P {
    int val, num;
    P(int val=0, int num=0): val(val), num(num) {}
};

struct S {
    P a, b;
    S(P a=P(), P b=P()): a(a), b(b) {}
};

S OP(S x, P p){
    if(p.val == x.a.val) {
        x.a.num += p.num;
        return x;
    }
    if(p.val==x.b.val){
        x.b.num += p.num;
        return x;
    }
    if(p.val < x.b.val) return x;
    x.b = p;
    if(x.a.val<x.b.val) swap(x.a, x.b);
    return x;
}

S op(S x, S y){
    return OP(OP(x, y.a), y.b);
};

S e() {return S(P(-inf+1, 0), P(-inf, 0));}

int main(){
    int n, q;
    cin >> n >> q;
    segtree<S, op, e> t(n);
    rep(i, n){
        int a; cin >> a;
        t.set(i, S(P(a, 1), P(-inf, 0)));
    }

    rep(qi, q){
        int type; cin >> type;
        if(type==1){
            int p, x;
            cin >> p >> x;
            p--;
            t.set(p, S(P(x, 1), P(-inf, 0)));
        }
        if(type==2){
            int l, r; cin >> l >> r;
            l--;
            S s = t.prod(l, r);
            int ans = s.b.num;
            cout << ans << endl;
        }
    }

}
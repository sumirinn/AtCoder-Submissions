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



//https://qiita.com/drken/items/cce6fc5c579051e64fab
template<class Abel> struct WUF {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    //Abelは基本intかll
    WUF(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    //rankは根に対してのみ意味を持ち、葉までの距離のmaxを意味する
    //diff_weight[i]はiの根から見たiのポテンシャルを記録
    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        //根に到達したら根の番号を返す
        if (par[x] == x) {
            return x;
        }
        //経路圧縮
        else {
            //一つ上の頂点を取得
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    //根から見たその点のポテンシャルを返す
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    // weight(y) - weight(x) = w となるように merge する
    bool merge(int x, int y, Abel w) {
        // x と y それぞれについて、 root との重み差分を補正
        //wをいじる
        w += weight(x); w -= weight(y);

        //使うときは先にsame関数で繋がっているかを確認するのが吉
        // x と y の root へ (x と y が既につながっていたら false を返すようにした)
        x = root(x); y = root(y);
        if (x == y) return false;

        // rank[x] >= rank[y] となるように x と y を swap (それに合わせて w も符号反転します)
        if (rank[x] < rank[y]) swap(x, y), w = -w;

        // y (のroot) を x (のroot) の下にくっつける
        //rankは木の頂点についてのみ考える必要のある概念
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;

        //xから見たxの子への重さは変わらない。yだけ変わる。
        //座標圧縮は呼び出されたときに行う
        diff_weight[y] = w;
        return true;
    }

    //xから見たyのポテンシャルを返す
    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};



int main(){
    int n, m;
    cin >> n >> m;
    scc_graph g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        g.add_edge(u,v);
    }

    auto scc = g.scc();

    cout << scc.size() << endl;
    for(auto es : scc){
        cout << es.size() << " ";
        for(int v : es) cout << v << " ";
        cout << endl;
    }
}
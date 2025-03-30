#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using db = double; 
using ull = unsigned long long;
using ld = long double; 
using bl = bool;
const int inf = 1001001001; 
const ll INF = 3e18;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>; using vvvvi = vv<vvi>;
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vdb = vc<db>; using vvdb = vv<db>; using vvvdb = vv<vdb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using vs = vc<string>; using vvs = vv<string>;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define repp(i,n) for(ll i=1; i<=(n); i++)
#define drep(i,n) for(ll i=(n)-1; i>=0; i--)
#define nfor(i,s,n) for(ll i=s; i<n; i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
template<typename T> void chmax(T& x, T y) {x = max(x, y);}
template<typename T> void chmin(T& x, T y) {x = min(x, y);}
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define YN {cout << "Yes" << endl;}else{cout << "No" << endl;}
#define TKAK {cout << "Takahashi" << endl;}else{cout << "Aoki" << endl;}
#define next_p(v) next_permutation(v.begin(),v.end())
bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define fi first
#define se second
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint; //mint::set_mod(m);で定義できる
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
//using P = pair<db, int>;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

		// rank[x] >= rank[y] となるようにxとyをswap、それに合わせて w も符号反転
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
	int n, q;
	cin >> n >> q;
	WUF<ll> uf(n);

	vi ans;
	rep(i,q) {
		int a, b;
		ll d;
		cin >> a >> b >> d;
		a--; b--;
		if (uf.same(a,b)){
			if(uf.diff(b,a)==d) ans.pb(i);
			continue;
		}
		else{
			ans.pb(i);
			uf.merge(b,a,d);
		}
	}

	for(int e : ans) cout << e+1 << " ";
	cout << endl;
}
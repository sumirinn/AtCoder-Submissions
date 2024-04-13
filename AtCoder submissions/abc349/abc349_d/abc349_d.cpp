#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define rep2(i, a, b) for(int i = (a); i <= (b); i++)
#define rep3(i, a, b, c) for(int i = (a); i <= (b); i+=(c))
using ll = long long; using db = double;
using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;  using pdd = pair<double, double>;
const int inf = 1001001001; const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
//auto nex = calc_next で取得すると楽。
vector<vector<int> > calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int> > res(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<string, int>;
using MP = map<int, vector<int>>;
void chmax(int& x, int y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//97~122(a~z),65~90(A~Z)

int main(){
    ll l, r;
    cin >> l >> r;

    const int m = 62;
    vector<ll> p2(m,1);
    rep(i,m-1) p2[i+1] = p2[i]*2;
    //rep(i,m) cout << p2[i] << endl;
    vector<pll> ans;
    int st = 0;
    rep(i,m){
        if(l<=p2[i]){
            st = i;
            break;
        }
    }
    int g = 0;
    rep(i,m){
        if(r<p2[i]){
            g = i-1;
            break;
        }
    }

    auto f = [&](ll start, ll goal) -> void {
        if(start==goal) return;
        while(start!=goal){
            int n2 = 0;
            ll s = start;
            while(s%2==0){
                n2++;
                s /= 2;
            }
            int ac=0, wa=n2+1;
            while(ac+1<wa){
                int wj = (ac+wa)/2;
                if(p2[wj]*((start/p2[wj])+ll(1))<=goal) ac=wj;
                else wa = wj;
            }
            ans.emplace_back(start,p2[ac]*((start/p2[ac])+ll(1)));
            start = p2[ac]*((start/p2[ac])+ll(1));
        }
    };

    //cout << st << " " << g << endl;
    if(l==0){
        ans.emplace_back(0,p2[g]);
        f(p2[g], r);
    }
    else if(st>=g){
        f(l,r);
    }
    else{
        f(l,p2[st]);
        for(int i=st; i<g; i++) ans.emplace_back(p2[i],p2[i+1]);
        f(p2[g],r);
    }

    cout << ans.size() << endl;
    for(auto[v,w] : ans) cout << v << " " << w << endl;
}
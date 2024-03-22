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
//using mint = modint1000000007;
using P = pair<int, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
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
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto e = a;
    sort(e.begin(), e.end());
    ll pre = 0;
    rep(i,n){
        ll r = n - i;
        ll num = r*(e[i] - pre);
        if(num<=k && i!=n-1){
            k -= num;
        }
        else{
            pre += k/r;
            rep(j,n){
                a[j] -= pre;
                if(a[j]<0) a[j] = 0; 
            }
            k %= r;
            rep(j,n){
                if(k>0 && a[j]>0){
                    a[j]--;
                    k--;
                }
            }
            break;
        }
        pre = e[i];
    }

    rep(i,n) cout << a[i] << " ";
    cout << endl;
}
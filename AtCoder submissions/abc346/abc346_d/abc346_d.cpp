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
    string s;
    cin >> n >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];

    vector<ll> l0(n), l1(n), r0(n), r1(n);
    rep(i,n){
        if(s[i]=='0'){
            if(i%2==0) l1[i] = c[i];
            else l0[i] = c[i];
        }
        if(s[i]=='1'){
            if(i%2==0) l0[i] = c[i];
            else l1[i] = c[i];
        }
    }
    rep(i,n-1) l0[i+1] += l0[i];
    rep(i,n-1) l1[i+1] += l1[i];
    reverse(s.begin(), s.end());
    reverse(c.begin(), c.end());
    rep(i,n){
        if(s[i]=='0'){
            if(i%2==0) r1[i] = c[i];
            else r0[i] = c[i];
        }
        if(s[i]=='1'){
            if(i%2==0) r0[i] = c[i];
            else r1[i] = c[i];
        }
    }
    rep(i,n-1) r0[i+1] += r0[i]; 
    reverse(r0.begin(), r0.end());
    rep(i,n-1) r1[i+1] += r1[i]; 
    reverse(r1.begin(), r1.end());
    
    ll ans = INF;
    rep(i,n-1){
        //00
        ll cnt0 = 0;
        if(i%2==0) cnt0 += l0[i];
        else cnt0 += l1[i];
        if((n-i)%2==0) cnt0 += r0[i+1];
        else cnt0 += r1[i+1];
        ans = min(ans, cnt0);

        //11
        ll cnt1 = 0;
        if(i%2==0) cnt1 += l1[i];
        else cnt1 += l0[i];
        if((n-i)%2==0) cnt1 += r1[i+1];
        else cnt1 += r0[i+1];
        ans = min(ans, cnt1);
    }

    cout << ans << endl;
}
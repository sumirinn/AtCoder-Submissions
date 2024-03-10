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
using P = pair<ll, int>;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(int& x, int y) {x = min(x, y);}
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
//97~122(a~z),65~90(A~Z)


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll A = a[0], B = a[n-1];
    int cnt = n;
    map<ll, ll> mp, mpb;
    rep(i, n-1) mp[a[i]] = a[i+1];
    rep(i, n-1) mpb[a[n-1-i]] = a[n-1-i-1];

    int q;
    cin >> q;
    rep(qi, q){
        int t;
        cin >> t;
        if(t==1){
            ll x, y;
            cin >> x >> y;
            cnt++;
            if(x==B){
                mp[x] = y;
                B = y;
                mpb[B] = x;
            }
            else{
                ll k = mp[x];
                mp[x] = y;
                mp[y] = k;
                mpb[k] = y;
                mpb[y] = x;
            }
        }
        if(t==2){
            ll x;
            cin >> x;
            cnt--;
            if(A==x){
                A = mp[x];
            }
            if(B==x){
                B = mpb[x];
            }
            else{
                ll b = mpb[x];
                ll f = mp[x];
                mp[b] = f;
                mpb[f] = b;
            }
        }
    }
    
    ll ans = A;
    cout << ans << " ";
    rep(i, cnt-1){
        ans = mp[ans];
        cout << ans << " ";
    }
    cout << endl;
}
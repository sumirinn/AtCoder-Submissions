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
const ll INF = 1e18;
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
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> v1(n+1), v2(n+1);
    int mid = n / 2;
    rep(i,(1<<mid)){
        ll cnt1=0;
        int cnt2=0;
        rep(j,mid){
            if((i&(1<<j))!=0){
                cnt1 += a[j];
                cnt2++;
            }
        }
        v1[cnt2].pb(cnt1);
    }
    rep(i,(1<<(n-mid))){
        ll cnt1=0;
        int cnt2=0;
        rep(j,n-mid){
            if((i&(1<<j))!=0){
                cnt1 += a[mid+j];
                cnt2++;
            }
        }
        v2[cnt2].pb(cnt1);
    }
    rep(i,n+1){
        sort(v1[i].begin(),v1[i].end());
        sort(v2[i].begin(),v2[i].end());
    }

    ll ans = 0;
    rep(h,k+1){
        rep(i,v1[h].size()){
            int pos = lower_bound(v2[k-h].begin(),v2[k-h].end(),p-v1[h][i]+1) - v2[k-h].begin();
            ans += pos;
        }
    }
    cout << ans << endl;
}
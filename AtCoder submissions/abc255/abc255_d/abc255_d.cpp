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
using P = pair<ll, ll>;
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
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

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), af(n), ab(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    af[0] = a[0];
    ab[n-1] = a[n-1];
    rep(i, n-1){
        af[i+1] = af[i] + a[i+1]; 
        ab[n-2-i] = ab[n-1-i] + a[n-2-i];
    }

    rep(qi, q){
        ll x;
        cin >> x;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        if(pos==a.size()) cout << x*(ll)a.size() - af[a.size()-1] << endl;
        else cout << x*(ll)(pos+1)-af[pos] + ab[pos]-x*(ll)(n-pos+1) + a[pos] << endl;
    }
}
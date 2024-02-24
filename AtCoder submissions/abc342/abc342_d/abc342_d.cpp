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
using P = pair<int, int>;
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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int m = 1e3;
    vector<bool> isPrime(m+1, true);
    vector<int> primes;
    for(int i=2; i<=m; i++){
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j=i*i; j<=m; j += i) isPrime[j] = false;
    }

    rep(i, n){
        if(a[i]==0) continue;
        for(int p : primes){
            int P = p*p;
            while(a[i]%P==0) a[i] /= P;
        }
    }

    map<int, int> mp;
    rep(i, n) mp[a[i]]++;

    ll ans = 0;
    for(auto[i, j] : mp){
        if(i==0){
            ans += ll((n-j))*ll(j);
            ans += ll(j)*ll((j-1))/ll(2);
        }else{
            ans += ll(j)*ll((j-1))/ll(2);
        }
    }

    cout << ans << endl;
}
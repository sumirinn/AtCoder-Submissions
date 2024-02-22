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
    string s;
    cin >> n >> s;
    vector<P> w(n);
    rep(i, n){
        cin >> w[i].first;
        if(s[i]=='1') w[i].second = 1;
        else w[i].second = 0;
    }

    sort(w.begin(), w.end());

    int cnt = 0;
    rep(i, n) cnt += w[i].second;
    int ans = cnt;

    rep(i, n){
        if(w[i].second==0) cnt++;
        else cnt--;
        while(i+1<n-1 && w[i].first==w[i+1].first){
            if(w[i+1].second==0) cnt++;
            else cnt--;
            i++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
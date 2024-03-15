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
using P = pair<ll, ll>;
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
//97~122(a~z),65~90(A~Z)

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<int, int> mp, mpb;
    int f=0, b=0;
    repp(i,n){
        if(s[i-1]=='L'){
            if(f==i-1){
                f = i;
                mp[i] = i-1;
                mpb[i-1] = i;
            }
            else{
                int F = mpb[i-1];
                mp[F] = i;
                mp[i] = i-1;
                mpb[i-1] = i;
                mpb[i] = F;
            }
        }
        if(s[i-1]=='R'){
            if(b==i-1){
                b = i;
                mp[i-1] = i;
                mpb[i] = i-1;
            }
            else{
                int B = mp[i-1];
                mp[i-1] = i;
                mp[i] = B;
                mpb[B] = i;
                mpb[i] = i-1;
            }
        }
    }
    cout << f << " ";
    rep(i,n){
        f = mp[f];
        cout << f << " ";
    }
    cout << endl;
}
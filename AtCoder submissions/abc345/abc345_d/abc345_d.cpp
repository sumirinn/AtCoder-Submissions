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
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> p(n);
    rep(i,n) p[i] = i;
    bool ans = false;

    do{
        vector<vector<bool>> g(h, vector<bool>(w));
        auto f = [&](auto f, int now, vector<vector<bool>> v)->void{
            int s=0, t=0;
            while(v[s][t] && t<w){
                s++;
                if(s==h){
                    s=0;
                    t++;
                }
            }
            if(s==0 && t==w){
                ans = true;
                return;
            }
            if(now==n) return;

            int pos = p[now];
            auto V = v;
            bool ok1 = true;
            for(int i=s; i<s+a[pos]; i++){
                if(i>=h){
                    ok1 = false;
                    break;
                }
                for(int j=t; j<t+b[pos]; j++){
                    if(j>=w){
                        ok1 = false;
                        break;
                    }
                    if(v[i][j]) ok1 = false;
                    v[i][j] = true;
                }
            }
            if(ok1) f(f, now+1, v);

            bool ok2 = true;
            for(int i=s; i<s+b[pos]; i++){
                if(i>=h){
                    ok2 = false;
                    break;
                }
                for(int j=t; j<t+a[pos]; j++){
                    if(j>=w){
                        ok2 = false;
                        break;
                    }
                    if(V[i][j]) ok2 = false;
                    V[i][j] = true;
                }
            }
            if(ok2) f(f, now+1, V);
        };
        f(f, 0, g);
    }while(next_permutation(p.begin(),p.end()));

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
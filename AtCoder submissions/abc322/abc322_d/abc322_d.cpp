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
void chmin(int& x, int y) {x = min(x, y);}
//const int di[] = {0, 1, 0, -1};
//const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int n = 3, m = 4;
    vector<vector<string>> p(n, vector<string>(m));
    rep(i, n)rep(j, m) cin >> p[i][j];

    vector<vector<vector<string>>> s(n);
    rep(pi, n){
        rep(ri, 4){
            for(int di = -m; di<m; di++){
                for(int dj = -m; dj<m; dj++){
                    vector<string> np(m, string(m, '.'));
                    bool stop = false;
                    rep(i, m)rep(j, m){
                        if(p[pi][i][j]=='.') continue;
                        int ni = i + di, nj = j + dj;
                        if(ni<0 || nj<0 || ni>=m || nj>=m){
                            stop = true;
                            continue;
                        }
                        np[ni][nj] = '#';
                    }
                    if(stop) continue;
                    s[pi].push_back(np);
                }
            }

            auto pre = p[pi];
            rep(i, m)rep(j, m){
                p[pi][i][j] = pre[m-1-j][i];
            }
        }
    }

    for(auto p0 : s[0]){
        for(auto p1 : s[1]){
            for(auto p2 : s[2]){

                vector<vector<int>> cnt(m, vector<int>(m));

                auto put = [&](vector<string> t){
                    rep(i, m)rep(j, m){
                        if(t[i][j]=='#') cnt[i][j]++;
                    }
                };

                put(p0);
                put(p1);
                put(p2);
                bool ok = true;
                rep(i, m)rep(j, m){
                    if(cnt[i][j]!=1) ok = false;
                }
                if(ok){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}
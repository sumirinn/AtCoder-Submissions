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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int h, w, si, sj, n;
    cin >> h >> w >> si >> sj >> n;
    MP mpL, mpR, mpU, mpD;
    rep(ni, n){
        int i, j;
        cin >> i >> j;
        mpR[i].push_back(j);
        mpL[i].push_back(-j);
        mpD[j].push_back(i);
        mpU[j].push_back(-i);
    }

    auto init = [&](MP& mp, int r) {
        for(auto& p : mp){
            sort(p.second.begin(), p.second.end());
            p.second.push_back(r);
        }
    };
    init(mpR, w+1);
    init(mpL, 0);
    init(mpD, h+1);
    init(mpU, 0);

    auto f = [&](MP& mp, int i, int j, int l, int r){
        auto it = mp.find(i);
        if(it==mp.end()) return min(j+l, r-1);
        auto& is = it->second;
        int wj = *lower_bound(is.begin(), is.end(), j);
        return min(j+l, wj-1);
    };
    int q;
    cin >> q;
    rep(qi, q){
        char d; int l;
        cin >> d >> l;
        if(d=='R') sj = f(mpR, si, sj, l, w+1);
        if(d=='L') sj = -f(mpL, si, -sj, l, 0);
        if(d=='D') si = f(mpD, sj, si, l, h+1);
        if(d=='U') si = -f(mpU, sj, -si, l, 0);
        cout << si << " " << sj << endl;
    }
}
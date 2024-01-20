#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
int inf = 1001001001;
//97~122(a~z)

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    repp(i, h) cin >> s[i];

    int ans = inf;
    repp(i, h){
        if(w<k)break;
        P a = make_pair(0, 0); //cost, batu
        repp(j, k){
            if(s[i][j]=='.') a.first++; 
            if(s[i][j]=='x') a.second++;
        }
        if(a.second==0) ans = min(ans, a.first);
        for(int j=k; j<=w-1; j++){
            if(s[i][j]=='.') a.first++; 
            if(s[i][j]=='x') a.second++;
            if(s[i][j-k]=='.') a.first--; 
            if(s[i][j-k]=='x') a.second--;
            if(a.second==0) ans = min(ans, a.first);
        }
    }
    repp(j, w){
        if(h<k)break;
        P a = make_pair(0, 0); //cost, batu
        repp(i, k){
            if(s[i][j]=='.') a.first++; 
            if(s[i][j]=='x') a.second++;
        }
        if(a.second==0) ans = min(ans, a.first);
        for(int i=k; i<=h-1; i++){
            if(s[i][j]=='.') a.first++; 
            if(s[i][j]=='x') a.second++;
            if(s[i-k][j]=='.') a.first--; 
            if(s[i-k][j]=='x') a.second--;
            if(a.second==0) ans = min(ans, a.first);
        }
    }
    if(ans==inf) cout << -1 << endl;
    else cout << ans << endl;
}
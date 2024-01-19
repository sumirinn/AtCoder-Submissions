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
//97~122(a~z)

int main(){
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<P> heal;
    rep(i, m){
        int x, y;
        cin >> x >> y;
        heal.insert(make_pair(x, y));
    }

    int x = 0, y = 0;
    repp(i, s.size()){
        h--;
        if(h<0){
            cout << "No" << endl;
            return 0;
        }
        if(s[i]=='R')x++; 
        if(s[i]=='L')x--;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
        if(heal.count(make_pair(x, y)) && h<k){
            h = k;
            heal.erase(make_pair(x, y));
        }
    }

    cout << "Yes" << endl;
}
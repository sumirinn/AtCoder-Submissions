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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    char s[200009];
    rep(i, n) cin >> s[i];

    set<pair<int, int>> p;

    pair<int, int> pos = make_pair(0, 0);
    p.insert(pos);

    bool ans = false;
    rep(i, n){
        int x = pos.first, y = pos.second;
        if(s[i]=='R') pos = make_pair(x+1, y);
        if(s[i]=='L') pos = make_pair(x-1, y);
        if(s[i]=='U') pos = make_pair(x, y+1);
        if(s[i]=='D') pos = make_pair(x, y-1);
        if(p.count(pos)) ans = true;
        p.insert(pos);
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
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
//97~122(a~z)

int main(){
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> d;
    for(int i=n; i>=1; i--) d.push_back(make_pair(i, 0));

    rep(qi, q){
        int u;
        cin >> u;
        int w = d.size()-1;
        if(u==1){
            char c;
            cin >> c;
            int x = d[w].first, y = d[w].second;
            if(c=='R') d.push_back(make_pair(x+1, y));
            if(c=='L') d.push_back(make_pair(x-1, y));
            if(c=='U') d.push_back(make_pair(x, y+1));
            if(c=='D') d.push_back(make_pair(x, y-1));
        }
        if(u==2){
            int p;
            cin >> p;
            cout << d[w-p+1].first << " " << d[w-p+1].second << endl;
        }
    }
}
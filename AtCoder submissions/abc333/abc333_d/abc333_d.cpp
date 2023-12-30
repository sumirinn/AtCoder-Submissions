#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;
vector<int> g[300009];

int f(int pos, int ba){
    int r = 0;
    repp(i, g[pos].size()){
        int s = g[pos][i];
        if(s!=ba) r += f(s, pos);
        //cout << s << endl;
    }
    r++;
    return r;
}

int main(){
    cin >> n;
    int a, b;
    rep(i, n-1){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 300009;
    int cnt = g[1].size();

    if(cnt==1){
        cout << 1 << endl;
        return 0;
    }

    repp(i, cnt){
        int r = g[1][i];
        int l = n - f(r, 1) - 1;
        ans = min(ans, l);
    }

    cout << ans + 1 << endl;
}
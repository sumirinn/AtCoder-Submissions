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
    int h, w;
    char s[109][109];
    cin >> h >> w;
    rep(i, h)rep(j, w) cin >> s[i][j];

    rep(i, h)rep(j, w-1)if(s[i][j]=='T' && s[i][j+1]=='T'){
        s[i][j] = 'P';
        s[i][j+1] = 'C';
    }

    rep(i, h){
        rep(j, w) cout << s[i][j];
        cout << endl;
    }
}
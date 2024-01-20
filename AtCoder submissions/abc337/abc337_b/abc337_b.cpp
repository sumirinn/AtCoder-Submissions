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
    string s;
    cin >> s;

    if(s.size()==1){
        cout << "Yes" << endl;
        return 0;
    }

    bool ans = true;
    repp(i, s.size()-1){
        if(s[i]=='B' && s[i+1]=='A') ans = false;
        if(s[i]=='C' && s[i+1]=='A') ans = false;
        if(s[i]=='C' && s[i+1]=='B') ans = false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
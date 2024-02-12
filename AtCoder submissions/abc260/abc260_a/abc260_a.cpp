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
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    string s; cin >> s;
    if(s[0]==s[1] && s[1]!=s[2]){
        cout << s[2] << endl;
        return 0;
    }
    if(s[1]==s[2] && s[2]!=s[0]){
        cout << s[0] << endl;
        return 0;
    }
    if(s[2]==s[0] && s[0]!=s[1]){
        cout << s[1] << endl;
        return 0;
    }
    if(s[2]==s[0] && s[0]==s[1]){
        cout << -1 << endl;
        return 0;
    }
    cout << s[0] << endl;

}

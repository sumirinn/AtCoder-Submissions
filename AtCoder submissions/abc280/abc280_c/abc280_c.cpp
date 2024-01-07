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
    string s, t;
    cin >> s >> t;
    int ans = 0;
    repp(i, t.size()){
        if(i==t.size()) ans = i;
        else if(s[i]!=t[i]){
            ans = i;
            break;
        }
    }

    cout << ans + 1 << endl;
}
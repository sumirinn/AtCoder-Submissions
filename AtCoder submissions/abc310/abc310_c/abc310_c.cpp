#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string s[200009];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];

    set<string> ans;
    rep(i, n){
        if(ans.count(s[i])==0){
            reverse(s[i].begin(), s[i].end());
            if(ans.count(s[i])==0) ans.insert(s[i]);
        }
    }

    cout << ans.size() << endl;
}
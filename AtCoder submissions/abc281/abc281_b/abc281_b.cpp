#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

string s;

int main(){
    cin >> s;

    bool ans = true;

    if(int(s[0]) < 65 || 90 < int(s[0]) ) ans = false;
    if(int(s[s.size()-1]) < 65 || 90 < int(s[s.size()-1])) ans = false;
    if(int(s[1]) < 49 || 57 < s[1]) ans = false;
    if(s.size()>8) ans = false;
    for(int i=2; i<s.size()-1; i++){
        if(int(s[i]) < 48 || 57 < int(s[i])) ans = false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
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

string s, t;

int main(){
    cin >> s >> t;

    bool ans = false;

    if(s.size()>=t.size()){
        for(int i=0; i<=s.size()-t.size(); i++){
            bool c = true;
            for(int j=0; j<t.size(); j++) if(s[i+j]!=t[j]) c = false;
            if(c) ans = true;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
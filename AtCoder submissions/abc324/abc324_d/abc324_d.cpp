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
    int n;
    string s;
    cin >> n >> s;

    vector<int> sc(10);
    for(char c : s) sc[c-'0']++;
    
    ll cnt = 0;
    for(ll x=0; ; x++){
        string t = to_string(x*x);
        if(t.size() > s.size())break;
        vector<int> tc(10);
        for(char c : t) tc[c-'0']++;
        tc[0] += s.size() - t.size();
        if(sc==tc) cnt++;
    }

    cout << cnt << endl;
}
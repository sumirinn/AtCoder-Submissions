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

int n;
string t, s[500009];
vector<int> ans;

int ham(string x, string y){
    if(x.size()!=y.size()) return 999;
    int res = 0;
    for(int i=0; i<x.size(); i++) if(x[i]!=y[i]) res++;
    return res;
}

bool f(string x, string y){
    if(x.size()!=y.size()+1) return false;
    int si = 0;
    for(int ti=0; ti<y.size(); ti++){
        while(si<x.size() && x[si]!=y[ti]) si++;
        if(si==x.size()) return false;
        si++;
    }
    return true;
}

int main(){
    cin >> n >> t;
    rep(i, n) cin >> s[i];

    rep(i, n){
        bool b = false;
        if(s[i].size()+1>=t.size()){
            if(ham(s[i], t)<=1) b = true;
            if(f(s[i], t)) b = true;
            if(f(t, s[i])) b = true;
        }
        if(b) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
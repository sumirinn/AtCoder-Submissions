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

bool solve(){
    int n;
    cin >> n;
    string s[100];
    rep(i, n) cin >> s[i];
    const string c1 = "HDCS";
    const string c2 = "A23456789TJQK";

    rep(i, n){
        if(c1.find(s[i][0]) == string::npos) return false;
        if(c2.find(s[i][1]) == string::npos) return false;
    }

    rep(i, n)rep(j, n)if(i!=j)if(s[i]==s[j]) return false;
    
    return true;

}

int main(){
    if(solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
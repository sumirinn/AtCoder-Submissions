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
char s[109];
bool ans=false;

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];
    rep(i, n-1){
        if(s[i]=='a' && s[i+1]=='b') ans =true;
        if(s[i]=='b' && s[i+1]=='a') ans =true;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
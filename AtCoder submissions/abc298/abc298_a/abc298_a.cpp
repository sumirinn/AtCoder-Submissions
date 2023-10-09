#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
char s[109];

int main(){
    cin >> n;
    rep(i,n) cin >> s[i];
    
    int ans1 = 0;
    bool ans2 = true;
    
    rep(i, n){
        if(s[i]=='o') ans1++;
        if(s[i]=='x') ans2 = false;
    }
    
    if(ans1!=0 && ans2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

char s[10];

int main(){
    rep(i, 8) cin >> s[i];
    
    bool ans = true;
    
    //1
    int a1 = 0, a2 = 0;
    for(int i=1; i<=8; i++) if(a1==0 || s[i]=='B') a1 = i;
    for(int i=8; i>=1; i--) if(a2==0 || s[i]=='B') a2 = i;
    if((a2-a1)%2==0) ans = false;
    
    //2
    int cnt = 0;
    rep(i, 8){
        if(s[i]=='R') cnt++;
        if(s[i]=='K' && cnt!=1) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
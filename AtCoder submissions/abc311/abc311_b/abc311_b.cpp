#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, d;
char s[109][109];

int main(){
    cin >> n >> d;
    rep(i, n)rep(j, d) cin >> s[i][j];
    
    int ans = 0;
    bool h[109];
    rep(i, d){
        bool cnt = true;
        rep(j, n) if(s[j][i]=='x') cnt =false;
        if(cnt) h[i] = true;
        else h[i] = false;
    }
    int count = 0;
    rep(i, d){
        if(h[i]) count++;
        else{
            ans = max(ans, count);
            count = 0;
        }
        ans = max(ans, count);
    }
    
    cout << ans << endl;
}
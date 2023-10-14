#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

char s[10][10];

int main(){
    int n = 8;
    rep(i, n)rep(j, n) cin >> s[i][j];
    
    char ans1;
    int ans2;
    
    rep(i, n)rep(j, n){
        if(s[i][j]=='*'){
            ans2 = n - i + 1;
            if(j==8) ans1 = 'h';
            if(j==7) ans1 = 'g';
            if(j==6) ans1 = 'f';
            if(j==5) ans1 = 'e';
            if(j==4) ans1 = 'd';
            if(j==3) ans1 = 'c';
            if(j==2) ans1 = 'b';
            if(j==1) ans1 = 'a';
        }
    }
    
    cout << ans1 << ans2 << endl;
}
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
    rep(i, n) cin >> s[i];
    
    int cnt = 0;
    
    rep(i, n){
        if(s[i]=='|') cnt++;
        
        if(s[i]=='*'){
            if(cnt==1) cout << "in" << endl;
            else cout << "out" << endl;
            
            return 0;
        }  
    }
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
char s[109][109];

int main(){
    cin >> n;
    rep(i, n) rep(j, n) cin >> s[i][j];
    
    int d[109];
    rep(i, n){
        int cnt = 0;
        rep(j, n){
            if(s[i][j]=='o') cnt++;
        }
        d[i] = cnt;
    }
    
    for(int j=100; j>=0; j--){
        for(int i=1; i<=n; i++){
            if(d[i]==j) cout << i << " ";
        }
    }
    
    cout << endl;
}
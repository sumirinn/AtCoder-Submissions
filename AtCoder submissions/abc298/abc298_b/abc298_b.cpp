#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, a[109][109], b[109][109], a1[109][109], a2[109][109], a3[109][109];

int main(){
    cin >> n;
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) cin >> b[i][j];
    
    bool ans = false;
    
    rep(i, n)rep(j, n) a1[i][j] = a[n+1-j][i];
    rep(i, n)rep(j, n) a2[i][j] = a1[n+1-j][i];
    rep(i, n)rep(j, n) a3[i][j] = a2[n+1-j][i];
    
    bool onj0 = true;
    rep(i, n)rep(j, n) if(a[i][j]==1 && b[i][j]!=1) onj0 = false;
    if(onj0) ans = true;
    
    bool onj1 = true;
    rep(i, n)rep(j, n) if(a1[i][j]==1 && b[i][j]!=1) onj1 = false;
    if(onj1) ans = true;
    
    bool onj2 = true;
    rep(i, n)rep(j, n) if(a2[i][j]==1 && b[i][j]!=1) onj2 = false;
    if(onj2) ans = true;
    
    bool onj3 = true;
    rep(i, n)rep(j, n) if(a3[i][j]==1 && b[i][j]!=1) onj3 = false;
    if(onj3) ans = true;
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
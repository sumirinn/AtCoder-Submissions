#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m, a[59][59];

int main(){
    cin >> n >> m;
    rep(i, m){
        rep(j, n) cin >> a[i][j];
    }
    
    bool f[59][59];
    rep(i, n) rep(j, n) f[i][j] = false;
    rep(i, m){
        rep(j, n-1){
            f[a[i][j]][a[i][j+1]] = true;
            f[a[i][j+1]][a[i][j]] = true;
        }
    }
    rep(i, n) f[i][i] = true;
    int ans = 0;
    
    rep(i, n){
        rep(j, n) if(!f[i][j]) ans++;
    }
    
    cout << ans / 2 << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m, p[109], c[109], f[109][109];

int main(){
    cin >> n >> m;
    rep(i, n){
        cin >> p[i] >> c[i];
        rep(j, c[i]) cin >> f[i][j];
    }
    
    bool ff[10009][10009];
    
    rep(i, n){
        rep(j, c[i]) ff[i][f[i][j]] = true;
    }
    
    bool ans = false;
    
    rep(i, n){
        rep(j, n){
            if(p[i]>=p[j]){
                bool che1 = true;
                bool che2 = false;
                rep(k, m) if(ff[i][k] && !ff[j][k]) che1 = false;
                if(p[i]>p[j]) che2 = true;
                rep(k, m) if(!ff[i][k] && ff[j][k]) che2 = true;
                if(che1 && che2) ans = true;
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
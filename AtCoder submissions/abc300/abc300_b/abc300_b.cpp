#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int h, w;
char a[39][39], b[39][39];

int main(){
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];
    
    rep(s, h){
        rep(t, w){
            bool ans = true;
            rep(i, h){
                rep(j, w){
                    if(a[(i-s+h)%h][(j-t+w)%w]!=b[i][j]) ans = false;
                }
            }
            if(ans==true){
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    
    cout << "No" << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int a[10][10];

int main(){
    rep(i, 9) rep(j, 9) cin >> a[i][j];

    bool ans = true;

    rep(i, 9){
        bool s[9];
        rep(i, 9) s[i] = false;
        rep(j, 9) s[a[i][j]] = true;
        rep(j, 9) if(s[j]==false) ans = false;
    }

    rep(i, 9){
        bool s[9];
        rep(i, 9) s[i]=false;
        rep(j, 9) s[a[j][i]] = true;
        rep(j, 9) if(s[j]==false) ans = false;
    }

    bool A[10][10];
    rep(i, 9) rep(j, 9) A[i][j] = false;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            A[1][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[1][i]==false) ans = false;
    for(int i=4; i<=6; i++){
        for(int j=1; j<=3; j++){
            A[2][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[2][i]==false) ans = false;
    for(int i=1; i<=3; i++){
        for(int j=7; j<=9; j++){
            A[3][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[3][i]==false) ans = false;
    for(int i=4; i<=6; i++){
        for(int j=1; j<=3; j++){
            A[4][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[4][i]==false) ans = false;
    for(int i=4; i<=6; i++){
        for(int j=4; j<=6; j++){
            A[5][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[5][i]==false) ans = false;
    for(int i=4; i<=6; i++){
        for(int j=7; j<=9; j++){
            A[6][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[6][i]==false) ans = false;
    for(int i=7; i<=9; i++){
        for(int j=1; j<=3; j++){
            A[7][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[7][i]==false) ans = false;
    for(int i=7; i<=9; i++){
        for(int j=4; j<=6; j++){
            A[8][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[8][i]==false) ans = false;
    for(int i=7; i<=9; i++){
        for(int j=7; j<=9; j++){
            A[9][a[i][j]] = true;
        }
    }
    rep(i, 9) if(A[9][i]==false) ans = false;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
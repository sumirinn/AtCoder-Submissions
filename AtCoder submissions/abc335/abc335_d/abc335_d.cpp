#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
//97~122(a~z)

int main(){
    int n;
    cin >> n;

    int d[50][50];
    int x = 0, y = 0, xx = -1, yy = 0, mx = 1, my = 1; 
    int num = 0;
    int X = (n+1)/2, Y = (n+1)/2;

    rep(i, n*n){
        d[Y][X] = num;
        num++;
        if(xx!=0){
            x = x + xx;
            X += xx;
        }
        if(yy!=0){
            y = y + yy;
            Y += yy;
        }
        if(abs(x)==mx){
            mx++;
            if(xx<0) yy = -1;
            else yy = 1;
            x = 0;
            xx = 0;
        }
        if(abs(y)==my){
            my++;
            if(yy<0) xx = 1;
            else xx = -1;
            y = 0;
            yy = 0;
        }
    }

    rep(i, n){
        rep(j, n){
            if(d[i][j]==0) cout << 'T' << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
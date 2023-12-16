#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int M, D, y, m, d;

int main(){
    cin >> M >> D >> y >> m >> d;

    if(d==D){
        if(m==M){
            y++; 
            m = 1; 
            d = 1;
        }else{
            m++;
            d = 1;
        }
    }else{
        d++;
    }

    cout << y << " " << m << " " << d << endl;
}
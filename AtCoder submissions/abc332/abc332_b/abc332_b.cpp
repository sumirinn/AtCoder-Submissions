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

int k, g, m;

int main(){
    cin >> k >> g >> m;

    int water[10];

    water[1] = 0; //glass  = g
    water[2] = 0; //mugcup = m

    rep(i, k){
        if(water[1]==g){
            water[1] = 0;
        }else if(water[2]==0){
            water[2] = m;
        }else{
            if(water[2]<=g-water[1]){
                water[1] += water[2];
                water[2] = 0;
            }else{
                water[2] -= (g-water[1]);
                water[1] = g;
            }
        }
    }

    cout << water[1] << " " << water[2] << endl;
}
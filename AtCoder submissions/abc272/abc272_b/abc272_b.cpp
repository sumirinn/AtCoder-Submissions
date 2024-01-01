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
//97~122

int n, m, k[109], x[109][109];

int main(){
    cin >> n >> m;
    rep(i, m){
        cin >> k[i];
        rep(j, k[i]){
            cin >> x[i][j];
        }
    }

    bool ans[109][109];
    rep(i, n)rep(j, n) ans[i][j] = false;
    rep(i, m){
        rep(j, k[i]){
            rep(l, k[i]){
                ans[x[i][j]][x[i][l]] = true; 
            }
        }
    }

    bool anss = true;
    rep(i, n){
        rep(j, n){
            if(!ans[i][j]) anss = false;
        }
    }

    if(anss) cout << "Yes" << endl;
    else cout << "No" << endl;
}
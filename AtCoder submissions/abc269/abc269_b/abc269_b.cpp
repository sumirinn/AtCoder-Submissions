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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    char s[19][19];
    rep(i, 10)rep(j, 10) cin >> s[i][j];

    int a=0, b=0, c=0, d=0;

    rep(i, 10){
        rep(j, 10){
            if(s[i][j]=='#' && a==0) a = i;
            if(s[i][j]=='#') b = max(b, i);
            if(s[i][j]=='#' && c==0) c = j;
            if(s[i][j]=='#') d = max(d, j);
        } 
    }

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
}
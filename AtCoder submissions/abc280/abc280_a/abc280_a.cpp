#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int h, w;
char s[19][19];

int main(){
    cin >> h >> w;
    rep(i, h)rep(j, w) cin >> s[i][j];

    int cnt = 0;
    rep(i, h)rep(j, w)if(s[i][j]=='#') cnt++;
    
    cout << cnt << endl;
}
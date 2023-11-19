#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)

int n, k;
char s[109];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> s[i];

    int cnt = 0;
    rep(i, n){
        if(s[i]=='o'){
            if(cnt < k) cnt++;
            else s[i] = 'x';
        }
    }

    rep(i, n) cout << s[i];
    cout << endl;
}
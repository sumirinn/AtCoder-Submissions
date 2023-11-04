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

int n; 
char s[5009];
int ans[5009];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];

    rep(i, n-1){
        int cnt = 0;
        while(i+cnt+1<=n){
            if(s[cnt+1]==s[cnt+1+i]) break;
            cnt++;
        }
        ans[i] = cnt;
    }

    rep(i, n-1) cout << ans[i] << endl;
}
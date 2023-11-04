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

int n, q, t[500009], x[500009];
char s[500009], c[500009];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];
    cin >> q;
    rep(i, q) cin >> t[i] >> x[i] >> c[i];

    int end = 0;
    for(int i=q; i>=1; i--){
        if(t[i]!=1){
            end = i;
            break;
        }
    }

    rep(i, end-1) if(t[i]==1) s[x[i]] = c[i];
    if(t[end]==2) rep(i, n) if('A'<=s[i] && s[i]<='Z') s[i] = char(s[i]-'A'+'a');
    if(t[end]==3) rep(i, n) if('a'<=s[i] && s[i]<='z') s[i] = char(s[i]-'a'+'A');

    for(int i=end+1; i<=q; i++){
        if(t[i]==1) s[x[i]] = c[i];
    }

    rep(i, n) cout << s[i];
    cout << endl;
}

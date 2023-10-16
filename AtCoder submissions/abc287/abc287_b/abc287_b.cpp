#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m, s[1009], t[1009];

int main(){
    cin >> n >> m;
    rep(i, n){
        cin >> s[i];
        s[i] = s[i] % 1000;
    }
    rep(i, m) cin >> t[i];
    
    int ans = 0;
    rep(i, n){
        bool a = false;
        rep(j, m){
            if(s[i]==t[j]) a = true;
        }
        if(a) ans++;
    }
    
    cout << ans << endl;
}
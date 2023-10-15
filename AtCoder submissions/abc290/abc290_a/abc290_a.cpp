#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int m, n;
int a[109], b[109];

int main(){
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    
    
    int ans = 0;
    rep(i,m){
        ans += a[b[i]];
        
    }
    
    cout << ans << endl;
}
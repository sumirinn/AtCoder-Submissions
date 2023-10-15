#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, a[109];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    
    bool ans = true;
    rep(i, n-1) if(a[i]!=a[i+1]) ans = false;
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
long long d, t[109];

int main(){
    cin >> n >> d;
    rep(i, n) cin >> t[i];
    
    int ans = -1;
    
    rep(i, n-1) if(t[i+1]-t[i]<=d && ans==-1) ans = t[i+1]; 
    
    cout << ans << endl;

}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, p[109];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    
    int ans = p[1];
    p[1] = 0;
    
    sort(p+1, p+n+1);
    
    if(p[n]-ans>=0) cout << p[n] + 1 - ans << endl;
    else cout << 0 << endl;
    
}
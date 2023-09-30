#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, k, x[109];

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> x[i];
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        int d = abs(x[i]-k);
        if(d<=x[i]) ans = ans + 2 * d;
        else ans = ans + x[i] * 2;
    }
    
    cout << ans << endl;
}
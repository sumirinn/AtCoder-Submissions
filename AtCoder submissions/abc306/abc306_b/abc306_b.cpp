#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

unsigned long long ans = 0;
unsigned long long tw[100];

int main(){
    tw[1] = 1; 
    for(int i=2; i<=64; i++) tw[i] = tw[i-1] * 2;
    
    rep(i, 64){
        int t = 0;
        cin >> t;
        if(t) ans += tw[i];
    }
    
    cout << ans << endl;
}

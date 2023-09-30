#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k;
int ans = 0;

int main(){
    cin >> k;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            for(int l=1; l<=k; l++){
                int gcd = 1;
                int m = min(i, j);
                m = min(m, l);
                for(int s=1; s<=m; s++) if(i%s==0 && j%s==0 && l%s==0) gcd = s;
                ans = ans + gcd;
            }
        }
    }
    
    cout << ans << endl;
}
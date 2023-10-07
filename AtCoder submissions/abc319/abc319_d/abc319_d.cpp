#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m;
long long l[200009];

int main(){
    cin >> n >> m;
    rep(i, n) cin >> l[i];
    
    long long lM = -1;
    rep(i, n) lM += l[i] + 1;
    long long lm = 0;
    rep(i, n) lm = max(lm, l[i]);
    
    while(lm<lM){
        long long a = (lM + lm) / 2;
        
        int r = 1;
        long long w = 0;
        rep(i, n){
            if(a-w>=l[i]) w += l[i] + 1;
            else{
                r++;
                w = l[i] + 1;
            }
        }
        
        if(r>m) lm = a + 1;
        else lM = a;
    
    }
    cout << lM << endl;
}
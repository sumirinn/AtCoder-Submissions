#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, d;
long long p, f[200009];

int main(){
    cin >> n >> d >> p;
    rep(i, n) cin >> f[i];
    
    sort(f+1, f+n+1);
    
    long long s[200009];
    s[0] = 0;
    rep(i, n) s[i] = s[i-1] + f[i];
    
    int pas = n / d + 1;
    long long ans = p * pas;
    for(int i=0; i<pas; i++){
        ans = min(ans, s[n-i*d]+i*p);
    }
    
    cout << ans << endl;
}
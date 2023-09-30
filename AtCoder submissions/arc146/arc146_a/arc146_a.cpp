#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long n, a[200009];

long long d(long long x){
    string s;
    s = to_string(x);
    long long ans = 1;
    for(int i=0; i<s.size(); i++){
        ans = ans * 10;
    }
    return ans;
}


long long c(long long  x, long long y, long long z){
    return x + y * d(x) + z * d(x) * d(y);
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    
    sort(a+1, a+n+1);
    
    long long x = a[n], y = a[n-1], z = a[n-2];
    long long m = max(c(x,y,z), c(x,z,y));
    long long mm = max(c(y,x,z),c(y,z,x));
    long long mmm = max(c(z,x,y), c(z,y,x));
    m = max(m, mm);
    m = max(m, mmm);
    
    cout << m << endl;
}
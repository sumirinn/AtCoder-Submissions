#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long Power(long long a, long long b, long long m){
    long long p = a, ans = 1;

    for(int i=0; i<60; i++){
        long long wari = (1LL<<i);
        if((b/wari)%2==1) ans = (ans * p) % m;
        
        p = (p * p) % m;
    }

    return ans;
}

int main(){
    long long a, b;
    cin >> a >> b;

    cout << Power(a, b, 1000000007) << endl;
}
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

long long Division(long long a, long long b, long long m){
    return(a * Power(b, m-2, m)) % m;
}

int main(){
    long long m = 1000000007;
    long long h, w;
    cin >> h >> w;

    long long a = 1;
    for(int i=1; i<=h+w-2; i++) a = (a * i) % m;

    long long b = 1;
    for(int i=1; i<=h-1; i++) b = (b * i) % m;
    for(int i=1; i<=w-1; i++) b = (b * i) % m;

    cout << Division(a, b, m) << endl;
}
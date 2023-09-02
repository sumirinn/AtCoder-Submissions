#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int N, a[100000009];

int main(){
    long long N;
    cin >> N;

    a[1] = 1;
    a[2] = 1;
    for(int i=3; i<=N; i++) a[i] = (a[i-1]+a[i-2]) % 1000000007;

    cout << a[N] << endl;
}
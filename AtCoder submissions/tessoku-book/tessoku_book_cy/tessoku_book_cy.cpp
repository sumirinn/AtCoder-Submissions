#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool notPrime[1000009];
int N = 0;
int main(){
    cin >> N;

    for(int i=1; i<=N; i++) notPrime[i] = false;

    for(int i=2; i*i<=N; i++){
        if(notPrime[i]==true) continue;
        for(int j=i*2; j<=N; j+=i) notPrime[j] = true;
    }

    for(int i=2; i<=N; i++){
        if(notPrime[i]==false) cout << i << endl;
    }
}
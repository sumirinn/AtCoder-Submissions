#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a1 = n/3;
    long long a2 = n/5;
    long long a3 = n/7;
    long long a4 = n/15;
    long long a5 = n/35;
    long long a6 = n/21;
    long long a7 = n/105;

    cout << a1+a2+a3-a4-a5-a6+a7 << endl;
}
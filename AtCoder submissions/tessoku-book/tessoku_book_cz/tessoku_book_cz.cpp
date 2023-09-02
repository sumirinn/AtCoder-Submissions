#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long GCD(long long A, long long B){
    while(A>=1 && B>=1){
        if(A>=B){
            A = A % B;
        }else{
            B = B % A;
        }
    }

    if(A!=0) return A;
    else return B;
}
int main(){
    long long A, B;
    cin >> A >> B;

    long long ans = (A * B) / GCD(A, B);

    cout << ans << endl;
}
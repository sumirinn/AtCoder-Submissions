#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

long long b;

int main(){
    cin >> b;

    long long a = 1;
    long long ans = 1;
    long long i = 1;
    while(true){
        long long A = 1;
        rep(s, i) A *= i;

        if(A==b){
            ans = i; 
            break;
        }
        if(A>b){
            ans = -1; 
            break;
        }
        i++;
    }
    cout << ans << endl;
}
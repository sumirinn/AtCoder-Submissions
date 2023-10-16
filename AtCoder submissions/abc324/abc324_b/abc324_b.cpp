#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

long long n;

int main(){
    cin >> n;
    
    while(n%2==0) n = n / 2;
    while(n%3==0) n = n / 3;
    
    if(n==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
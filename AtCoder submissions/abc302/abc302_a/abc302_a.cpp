#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

long long a, b;

int main(){
    cin >> a >> b;
    
    long long ans = a / b;
    if(a%b==0) cout << ans << endl;
    else cout << ans + 1 << endl;
}
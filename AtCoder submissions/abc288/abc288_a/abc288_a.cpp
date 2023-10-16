#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
    int n = 0;
    cin >> n;
    rep(i, n){
        long long a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int a, b;

int main(){
    cin >> a >> b;
    
    if(a==b/2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
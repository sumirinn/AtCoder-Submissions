#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int rui(int a, int b){
    int c = 1;
    for(int i=1; i<=b; i++){
        c *= a;
    }
    
    return c;
}

int a, b;

int main(){
    cin >> a >> b;
    
    cout << rui(a, b) + rui(b, a) << endl;
}
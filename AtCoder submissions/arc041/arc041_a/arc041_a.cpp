#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int x, y, k;

int main(){
    cin >> x >> y >> k;
    
    if(y>=k){
        cout << x + k << endl;
    }else{
        cout << x + y - (k - y) << endl;
    }
}
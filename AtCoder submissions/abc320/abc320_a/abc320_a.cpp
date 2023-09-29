#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

int main(){
    cin >> a >> b;
    
    int A = 1, B = 1;
    
    for(int i=1; i<=b; i++) A = A * a;
    for(int i=1; i<=a; i++) B = B * b;
    
    cout << A + B << endl;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n; 
string s;

int main(){
    cin >> n >> s;
    
    for(int i=0; i<n; i++) cout << s[i] << s[i];
    cout << endl;
}
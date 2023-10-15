#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

string s;

int main(){
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') cout << 1;
        if(s[i]=='1') cout << 0;
    }
    
    cout << endl;
}
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
    bool ans = true;
    for(int i=1; i<=15; i++){
        if(s[i]!='0') ans = false; 
        i = i + 1;
    }
    
    if(ans==true) cout << "Yes" << endl;
    else cout << "No" << endl;
}
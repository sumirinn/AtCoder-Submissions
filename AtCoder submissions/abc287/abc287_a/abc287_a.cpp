#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string s[109];

int main(){
    cin >>n;
    int f = 0, a = 0;
    rep(i, n){
        cin >> s[i];
        if(s[i]=="For") f++;
        else a++;
    }
    
    if(f>=a) cout << "Yes" << endl;
    else cout << "No" << endl;
}
    

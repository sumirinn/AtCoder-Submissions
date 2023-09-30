#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
string s, t;
bool mae=true, usiro=true;

int main(){
    cin >> n >> m >> s >> t;
    
    for(int i=0; i<n; i++){
        if(s[i]!=t[i]) mae = false;
    }
    
    for(int i=n-1; i>=0; i--){
        if(s[i]!=t[m-n+i]) usiro = false;
    }
    
    int ans = 100;
    
    if(mae==true && usiro==true) ans = 0;
    if(mae==true && usiro==false) ans = 1;
    if(mae==false && usiro==true) ans = 2;
    if(mae==false && usiro==false) ans = 3;
    
    cout << ans << endl;
    
}
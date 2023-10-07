#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string s, t;

bool check(char a, char b){
    bool c = false;
    if(a==b) c = true;
    if(a=='1' && b=='l') c = true;
    if(a=='l' && b=='1') c = true;
    if(a=='0' && b=='o') c = true;
    if(a=='o' && b=='0') c = true;
    return c;
}
int main(){
    cin >> n >> s >> t;
    
    bool ans = true;
    
    for(int i=0; i<n; i++){
        if(!check(s[i], t[i])) ans = false;
    }
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
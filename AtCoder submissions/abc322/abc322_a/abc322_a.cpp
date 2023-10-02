#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;
    int ans = -1;
    
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            ans = i+1;
            break;
        }
    }
    
    cout << ans << endl;
}
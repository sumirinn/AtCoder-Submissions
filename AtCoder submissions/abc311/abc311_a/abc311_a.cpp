#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n;
string s;
bool ans[10];

int main(){
    cin >> n >> s;
    
    ans[1] = false;
    ans[2] = false;
    ans[3] = false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A') ans[1] = true;
        if(s[i]=='B') ans[2] = true;
        if(s[i]=='C') ans[3] = true;
        
        if(ans[1] && ans[2] && ans[3]){
            cout << i + 1 << endl;
            return 0;
        }
    }
}
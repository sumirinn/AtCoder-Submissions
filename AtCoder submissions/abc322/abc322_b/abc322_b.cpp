#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
string s, t;

int main(){
    cin >> n >> m >> s >> t;
    
    bool ans1 = true;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=t[i]) ans1 = false;
    }
    
    bool ans2 = true;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=t[m-n+i]) ans2 = false;
    }
    
    if(ans1){
        cout << (ans2 ? 0 : 1) << endl;
    }else{
        cout << (ans2 ? 2 : 3) << endl;
    }
}
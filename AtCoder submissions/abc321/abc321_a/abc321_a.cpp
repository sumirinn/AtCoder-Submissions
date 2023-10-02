#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string s;

int main(){
    cin >> s;
    for(int i=1; i<s.size(); i++){
        if(s[i-1]<=s[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
}
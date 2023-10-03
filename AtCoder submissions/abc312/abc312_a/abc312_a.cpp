#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string s;

int main(){
    cin >> s;
    
    if(s=="ACE" || s=="BDF" || s=="CEG" || s=="DFA" || s=="EGB" || s=="FAC" || s=="GBD") cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'){
            s.erase(s.begin()+i);
        }
    }

    cout << s << endl;
}
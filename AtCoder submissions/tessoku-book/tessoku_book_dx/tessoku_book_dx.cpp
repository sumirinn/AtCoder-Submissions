#include <iostream>
#include <algorithm>
#include <stack>
#include<string>
using namespace std;

string s;
stack<int> ans;

int main(){
    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') ans.push(i+1);
        if(s[i]==')'){
            cout << ans.top() << " " << i + 1 << endl;
            ans.pop();
        }
    }
}
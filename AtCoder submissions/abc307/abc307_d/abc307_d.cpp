#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int d=0;
    for(auto c:s){
        if(c==')'&&d>0){
            while(ans.back()!='(')ans.pop_back();
            ans.pop_back();
            d--;
        }else{
            ans+=c;
            if(c=='(')d++;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int d = 0;
    for(int i=0; i<n; i++){
        char c;
        c = s[i];
        if(c==')' && d>0){
            while(ans.back()!='('){
                ans.pop_back();
            }
            ans.pop_back();
            d--;
        }else{
            ans += c;
            if(c =='('){
                d++;
            }
        }
    }
    cout << ans << endl;
}
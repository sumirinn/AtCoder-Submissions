#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;
int k[100009];
int main(){
    cin >> s;
    t = s;
    int n = s.size();
    
    int ans = 0, a = 0, b = 0;
    
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    
    if(s[0]!='0'){
        s[0] = '0';
        a++;
    }
    if(s[1]!='1'){
        s[1] = '1';
        a++;
    }
    for(int i=2; i<n; i++){
        if(s[i]==s[i-1]){
            s[i] = s[i-2];
            a++;
        }
    }
    
     
    if(t[0]!='1'){
        t[0] = '1';
        b++;
    }
    if(t[1]!='0'){
        t[1] = '0';
        b++;
    }
    for(int i=2; i<n; i++){
        if(t[i]==t[i-1]){
            t[i] = t[i-2];
            b++;
        }
    }
    
    ans = min(a, b);
    
    cout << ans << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

string s;

int main(){
    cin >> s;
    string ans = "";
    for(int i=0; i<s.size(); i++){
        ans += s[i];
        if(ans.size()>=3){
            if(ans[ans.size()-3]=='A' && ans[ans.size()-2]=='B' && ans[ans.size()-1]=='C'){
                ans.erase(ans.size()-3, ans.size());
            }
        }
    }
    
    cout << ans << endl;
}
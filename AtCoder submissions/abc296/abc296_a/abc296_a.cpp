#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
string s, ans;

int main(){
    cin >> n >> s;

    ans = "Yes";

    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]) ans = "No";
    }

    cout << ans << endl;
}


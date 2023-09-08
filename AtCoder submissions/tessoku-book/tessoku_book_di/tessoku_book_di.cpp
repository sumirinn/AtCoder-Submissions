#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k;
char s[300009];

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> s[i];

    int CountON = 0;

    for(int i=1; i<=n; i++){
        if(s[i]=='1') CountON++;
    }

    if((CountON-k)%2==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
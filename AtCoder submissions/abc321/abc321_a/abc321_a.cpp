#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, a=1;
int v[10];
string ans = "Yes";

int main(){
    cin >> n;
    for(int i=1; i<=5; i++){
        v[i] = (n/a) % 10;
        a = a * 10;
    }

    int c = 0;
    v[0] = -1;

    for(int i=5; i>=1; i--){
        if(c==0){
            if(v[i]==0) continue;
        }

        c = 1;

        if(v[i]<=v[i-1]) ans = "No";
    }

    cout << ans << endl;
}
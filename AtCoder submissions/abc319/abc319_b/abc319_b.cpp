#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;

int main(){
    cin >> n;

    cout << 1;

    for(int i=1; i<=n; i++){
        int mini = 10;
        for(int j=1; j<=9; j++){
            if(n%j==0 && i%(n/j)==0 && i/(n/j)<10){
                mini = min(j, mini);
            }
        }

        if(mini==10) cout << "-";
        else cout << mini;
        }

    cout << endl;
}
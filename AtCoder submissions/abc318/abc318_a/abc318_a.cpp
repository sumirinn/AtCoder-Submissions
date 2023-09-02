#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    
    if(m>n){
        cout << 0 << endl;
    }else{
        ans = (n - m) / p + 1;
        cout << ans << endl;
    }
}
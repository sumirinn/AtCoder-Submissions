#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, x, ans;
int a[109];

int main(){
    cin >> n >> x;
    for(int i=1; i<=n-1; i++) cin >> a[i];

    int s = 0, m = 1000, M = -1;
    for(int i=1; i<=n-1; i++){
        s = s + a[i];
        m = min(m, a[i]);
        M = max(M, a[i]);
    }

    if(x>s-m){
        cout << -1 << endl;
        return 0;
    }

    if(x<=s-M){
        cout << 0 << endl;
        return 0;
    }

    cout << x - (s - m - M) << endl;
    return 0;
}
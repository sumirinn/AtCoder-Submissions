#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, m, a[200009];

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> a[i];
    
    for(int i=1; i<=n; i++){
        int ans = 0;
        int pos = lower_bound(a+1, a+m+1, i) - a;
        ans = a[pos] - i;
        cout << ans << endl;
    }
}
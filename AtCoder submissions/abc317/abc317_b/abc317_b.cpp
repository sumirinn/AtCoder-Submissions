#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
int a[109];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    a[n+1] = 100000;
    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++){
        if(a[i+1]-a[i]==2) ans = a[i]+1;
    }

    cout << ans << endl;
}
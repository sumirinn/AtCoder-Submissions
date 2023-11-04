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

int n;
long long a[200009];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    sort(a+1, a+n+1);
    
    long long s = 0;
    long long ans = 0;
    rep(i, n) s += a[i];
    long long av = s / n;
    long long r = s % n;

    for(int i=1; i<=n-r; i++){
        if(a[i]>av) ans += a[i] - av;
    }
    for(int i=n-r+1; i<=n; i++){
        if(a[i]>av) ans += a[i] - av - 1;
    }

    cout << ans << endl;
}
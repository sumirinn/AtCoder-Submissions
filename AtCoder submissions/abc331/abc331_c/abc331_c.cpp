#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;
ll a[200009];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    ll b[200009];
    rep(i, n) b[i] = a[i];
    sort(b+1, b+n+1);
    
    ll c[200009];
    c[n+1] = 0;
    c[n] = b[n];
    for(int i=1; i<n; i++){
        c[n-i] = c[n-i+1] + b[n-i];
    }

    rep(i, n){
        int pos = lower_bound(b+1, b+n+1, a[i]+1) - b;
        cout << c[pos] << " ";
    }
    cout << endl;
}
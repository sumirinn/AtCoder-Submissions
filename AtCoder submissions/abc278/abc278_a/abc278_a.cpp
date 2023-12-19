#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n, k ,a[109];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    int cnt = 0;
    for(int i=k+1; i<=n; i++){
        cout << a[i] << " ";
        cnt++;
    }
    rep(i, k){
        cout << 0 << " ";
        cnt++;
        if(cnt==n) i=k;
    }
    cout << endl;
}
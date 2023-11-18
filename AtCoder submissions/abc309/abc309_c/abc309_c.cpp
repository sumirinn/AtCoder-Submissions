#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

long long n;
long long k, a[300009], b[300009];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> a[i] >> b[i];

    vector<pair<long long, long long>> v(n);
    rep(i, n){
        v[i-1].first = a[i];
        v[i-1].second = b[i];
    }
    sort(v.begin(), v.end());

    long long med = 0;
    rep(i, n) med += b[i];

    if(med<=k){
        cout << 1 << endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        med -= v[i].second;
        if(med<=k){
            cout << v[i].first + 1 << endl;
            return 0;
        }
    }
}
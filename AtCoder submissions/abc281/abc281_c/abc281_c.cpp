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
long long t;
int a[100009];

int main(){
    cin >> n >> t;
    rep(i, n) cin >> a[i];

    long long all[100009];
    rep(i,n) all[i] = 0;
    all[0] = 0;
    rep(i, n) all[i] = a[i] + all[i-1];

    t = t % all[n];

    rep(i, n){
        if(all[i-1] <= t && t <= all[i]){
            cout << i << " " << t - all[i-1] << endl;
        }
    }
}
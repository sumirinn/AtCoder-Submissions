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

int n, q;
long long a[100009];
int Q[100009];
long long k[100009], x[100009];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> q;
    rep(i, q){
        cin >> Q[i];
        if(Q[i]==1) cin >> k[i] >> x[i];
        if(Q[i]==2) cin >> k[i];
    }

    rep(i, q){
        if(Q[i]==1) a[k[i]] = x[i];
        if(Q[i]==2) cout << a[k[i]] << endl;
    }

}
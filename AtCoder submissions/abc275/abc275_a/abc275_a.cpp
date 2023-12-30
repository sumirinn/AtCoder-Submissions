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

int n;
ll h[109];

int main(){
    cin >> n;
    rep(i, n) cin >> h[i];

    int pos = 0;
    int m = 0;
    rep(i, n) {
        if(m<=h[i]){
            pos = i;
            m = h[i];
        }
    }

    cout << pos << endl;
}
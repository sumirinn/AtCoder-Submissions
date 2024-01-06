#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
//97~122(a~z)

int main(){
    int n;
    cin >> n;

    repp(i,n+1){
        repp(j, n+1-i){
            repp(k, n+1-i-j){
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
}
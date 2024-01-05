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
//97~122

int main(){
    int n, a[200009];
    cin >> n;
    rep(i, n) cin >> a[i];

    bool b[200009];
    rep(i, n) b[i] = true;
    int cnt = 0;

    rep(i, n){
        if(b[i]){
            b[a[i]] = false;
        }
    }
    rep(i, n)if(b[i]) cnt++;

    cout << cnt << endl;
    rep(i, n) if(b[i]) cout << i << " ";
    cout << endl;

}
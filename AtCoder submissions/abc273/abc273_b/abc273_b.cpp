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

ll x;
int k;

int main(){
    cin >> x >> k;

    ll cnt = 1;
    rep(i, k){
        ll a = x / cnt;
        a = a % 10;
        if(a>=5) x = x - a * cnt + 10 * cnt;
        else x = x - a * cnt;
        cnt *= 10;
    }

    cout << x << endl;
}
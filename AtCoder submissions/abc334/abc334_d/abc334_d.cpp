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

int N, Q;
ll r[200009], q[200009];

int main(){
    cin >> N >> Q;
    rep(i, N) cin >> r[i];
    rep(i, Q) cin >> q[i];

    sort(r+1, r+N+1);
    ll s[200009];
    s[0] = 0;
    rep(i, N) s[i] = s[i-1] + r[i];

    rep(i, Q){
        int pos = lower_bound(s, s+N+1, q[i]) - s;
        if(q[i]!=s[pos]) pos--;
        cout << pos << endl;
    }
}

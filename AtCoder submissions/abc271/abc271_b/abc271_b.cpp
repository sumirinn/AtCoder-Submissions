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
    int n, q, l[200009], s[200009], t[200009];
    vector<ll> a[200009];
    cin >> n >> q;
    rep(i, n){
        cin >> l[i];
        rep(j, l[i]){
            ll s;
            cin >> s;
            a[i].push_back(s); 
        }
    }

    rep(i, q){
        int s, t;
        cin >> s >> t;
        cout << a[s][t-1] << endl;
    }
}
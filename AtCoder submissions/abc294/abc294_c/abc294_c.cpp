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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    int n, m;
    cin >> n >> m;
    ll a[100009], b[100009];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];


    int posa = 1;
    int posb = 1;
    a[n+1] = 1e10;
    b[m+1] = 1e10;
    rep(i, n+m){
        if(a[posa]>b[posb]) b[posb] = i, posb++;
        else a[posa] = i, posa++;
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;
    rep(i, m) cout << b[i] << " ";
    cout << endl;
}
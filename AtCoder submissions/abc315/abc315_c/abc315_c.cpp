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
long long f[300009], s[300009];

int main(){
    cin >> n;
    rep(i, n) cin >> f[i] >> s[i];

    vector<vector<long long>> v(n+1);
    rep(i, n) v[f[i]].push_back(s[i]);
    rep(i, n){
        sort(v[i].begin(), v[i].end()); 
        reverse(v[i].begin(), v[i].end());
    }

    long long ans = 0;
    vector<long long> V;

    rep(i, n){
        if(v[i].size()>=2){
            long long a = v[i][0] + v[i][1] / 2;
            ans = max(ans, a);
        }
        if(v[i].size()>=1) V.push_back(v[i][0]);
    }

    sort(V.begin(), V.end()); 
    reverse(V.begin(), V.end());
    
    if(V.size()>=2) ans = max(ans, V[0]+V[1]);

    cout << ans << endl;
}
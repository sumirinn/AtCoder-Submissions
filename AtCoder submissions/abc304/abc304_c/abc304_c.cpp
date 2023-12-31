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

int n, d, x[2009], y[2009];

int main(){
    cin >> n >> d;
    rep(i, n) cin >> x[i] >> y[i];

    bool af[2009];
    rep(i, n) af[i] = false;
    af[1] = true;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int i = q.front(); q.pop();
        rep(j, n){
            int X = x[i] - x[j];
            int Y = y[i] - y[j];
            if(X*X+Y*Y<=d*d){
                if(af[j]) continue;
                af[j] = true;
                q.push(j);
            }
        }
    }

    rep(i, n){
        if(af[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll d;

int main(){
    cin >> d;

    ll ans = d;
    ll y = 2e6;

    for(ll x=0; x<=2e6; x++){
        while(y>0 && x*x+y*y>d){
            y--;
        }

        ans = min(ans, abs(x*x+y*y-d));
        ans = min(ans, abs(x*x+(y+1)*(y+1)-d));
    }

    cout << ans << endl;
}
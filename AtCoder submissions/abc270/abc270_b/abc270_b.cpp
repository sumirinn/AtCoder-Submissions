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
    int x, y, z;
    cin >> x >> y >> z;

    if(x*y<0) cout << abs(x) << endl;
    else{
        if(abs(x)<abs(y)) cout << abs(x) << endl;
        else{
            if(y*z<0) cout << abs(x) + 2 * abs(z) << endl;
            else{
                if(abs(z)<abs(y)) cout << abs(x) << endl;
                else cout << -1 << endl;
            }
        }
    }
}
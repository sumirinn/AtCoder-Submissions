#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int a, b;

int main(){
    cin >> a >> b;
    if(a==b){
        cout << "1.000" << endl;
        return 0;
    }
    if(b==0){
        cout << "0.000" << endl;
        return 0;
    }
    b = b * 10000;
    int ans = b / a;
    if(ans%10>=5) ans += 10;

    cout << 0 << '.' << ans/10 << endl;
}
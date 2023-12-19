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

int n, k;
ll l, a[100009];

int main(){
    cin >> n >> l >> k;
    rep(i, n) cin >> a[i];

    auto can_cut = [&](ll x) -> bool {
        ll num = 0;
        ll pre = 0;

        rep(i, n){
            if(a[i]-pre>=x){
                num++;
                pre = a[i];
            }
        }

            if(l-pre>=x) num++;

            return (num>=k+1);
    };

    ll left = 0, right = l + 1;

    while(right-left>1) {
        ll mid = (left + right) / 2;
        if(can_cut(mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
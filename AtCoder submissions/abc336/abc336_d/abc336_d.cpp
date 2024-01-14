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
using P = pair<int, int>;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    ll a[200009];
    ll ml[200009], mr[200009];
    rep(i, n) cin >> a[i];

    ll m = (n+1)/2;
    rep(i, n)if(a[i]>m) a[i] = m;
    if(a[1]==0) ml[1] = 0;
    else ml[1] = 1;
    if(a[n]==0) mr[n] = 0;
    else mr[n] = 1;
    rep(i, n-1){
        if(a[i]<a[i+1]) ml[i+1] = ml[i] + 1;
        if(a[i]==a[i+1]){
            if(a[i+1]>ml[i]) ml[i+1] =ml[i] + 1;
            else ml[i+1] = ml[i];
        }
        if(a[i]>a[i+1]){
            ml[i+1] = min(a[i+1], ml[i]+1);
        }
    }

    for(int i=n-1; i>=1; i--){
        if(a[i+1]<a[i]) mr[i] = mr[i+1] + 1;
        if(a[i+1]==a[i]){
            if(a[i]>mr[i+1]) mr[i] = mr[i+1] + 1;
            else mr[i] = mr[i+1];
        }
        if(a[i+1]>a[i]){
            mr[i] = min(a[i], mr[i+1]+1);
        }    
    }

    ll M[200009];
    rep(i, n) M[i] = min(mr[i], ml[i]);
    ll ans = -1;
    rep(i, n) ans = max(ans, M[i]);

    cout << ans << endl;
}
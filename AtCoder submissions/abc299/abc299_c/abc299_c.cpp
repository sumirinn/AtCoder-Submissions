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
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int d = 0;
    int type = 0;
    if(s[0]=='-') type = 1;
    while(d<n){
        int cnt = 0;
        if(s[d]=='o' && type==0){
            cnt++;
            d++;
            while(s[d]=='o' && d<n){
                d++;
                cnt++;
            }
            if(d==n) cnt = 0;
            ans = max(ans, cnt);
            type = 1;
            continue;
        }
        if(s[d]=='-' && type==1){
            d++;
            while(s[d]=='o' && d<n){
                d++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        else d++;
    }

    if(ans) cout << ans << endl;
    else cout << -1 << endl;
}
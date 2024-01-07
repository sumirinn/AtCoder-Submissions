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
    cin >> n;
    vector<P> a(n);
    repp(i, n){
        ll t, d;
        cin >> t >> d;
        a[i] = P(t, t+d);
    }
    sort(a.begin(), a.end());

    int ans = 0;
    ll t = 0;
    int ai = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    while(ai<n || !q.empty()){
        while(ai<n && a[ai].first<=t){
            q.push(a[ai].second);
            ai++;
        }
        while(!q.empty() && q.top()<t) q.pop();

        if(!q.empty()) ans++, q.pop();
        if(q.empty() && ai<n) t = a[ai].first;
        else t++;
    }

    cout << ans << endl;
}
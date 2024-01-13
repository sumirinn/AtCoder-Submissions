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
    string t;
    vector<string> s;
    cin >> n >> t;
    string S;
    rep(i, n){
        cin >> S;
        s.push_back(S);
    }

    vector<int> mae;
    vector<int> usi;
    repp(i, n){
        int now = 0;
        repp(j, s[i].size()){
            if(s[i][j]==t[now]) now++;
            if(now==t.size()) break;
        }
        mae.push_back(now);
    }
    repp(i, n){
        int now = t.size() - 1;
        for(int j= s[i].size()-1; j>=0; j--){
            if(s[i][j]==t[now]) now--;
            if(now==-1) break;
        }
        usi.push_back(t.size()-now-1);
    }

    sort(mae.begin(), mae.end());
    sort(usi.begin(), usi.end());
    ll ans = 0;
    
    int Mae[500009];
    rep(i, n) Mae[i] = mae[i-1];
    repp(i, n){
        int num = usi[i];
        int pos = lower_bound(Mae+1, Mae+n+1, t.size() - num) - Mae;
        ans += n - pos + 1;
    }
    cout << ans << endl;
}
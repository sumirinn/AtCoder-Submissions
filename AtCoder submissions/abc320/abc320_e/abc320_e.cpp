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
    int n, m;
    cin >> n >> m;
    ll t[200009], w[200009], s[200009], men[200009];
    rep(i, m) cin >> t[i] >> w[i] >> s[i];
    rep(i, n) men[i] = 0;

    priority_queue<int, vector<int>, greater<int>> Q;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> q;
    rep(i, n) Q.push(i);

    rep(i, m){
        while(!q.empty() && q.top().first<=t[i]){
            Q.push(q.top().second);
            q.pop();
        }
        if(!(Q.empty())){
            int p = Q.top(); 
            Q.pop();
            men[p] += w[i];
            q.push(make_pair(s[i]+t[i], p));
        }
    }

    rep(i, n) cout << men[i] << endl;
}
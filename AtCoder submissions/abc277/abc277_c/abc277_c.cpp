#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
//97~122(a~z),65~90(A~Z)

int main(){
    int n; cin >> n;

    map<ll, vector<ll>> to;
    rep(i, n){
        ll a, b; cin >> a >>b;
        to[a].emplace_back(b);
        to[b].emplace_back(a);
    }

    queue<ll> q;
    q.push(1);
    set<ll> s;
    s.insert(1);

    while(!q.empty()){
        ll pos = q.front(); q.pop();
        for(ll i : to[pos]){
            if(s.count(i)) continue;
            q.push(i);
            s.insert(i);
        }
    }

    cout << *s.rbegin() << endl;
}
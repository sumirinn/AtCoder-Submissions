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
    vector<P> c(2*n);
    rep(i, n){
        int a, b; cin >> a >> b; a--; b--;
        if(a>b) swap(a, b);
        c[a] = make_pair(1, i);
        c[b] = make_pair(0, i);
    }

    stack<int> d;
    rep(i, 2*n){
        if(c[i].first)d.push(c[i].second);
        else{
            if(c[i].second==d.top()) d.pop();
            else{
                cout << "Yes" << endl;
                return 0;
            }
        }
        
    }
    cout << "No" << endl;

}
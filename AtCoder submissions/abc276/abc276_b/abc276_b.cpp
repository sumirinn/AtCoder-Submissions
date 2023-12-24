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

int n, m;
vector<int> g[200009];

int main(){
    cin >> n >> m;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, n){
        sort(g[i].begin(), g[i].end());
        cout << g[i].size() << " ";
        repp(pos, g[i].size()) cout << g[i][pos] << " " ;
        cout << endl;
    }
}
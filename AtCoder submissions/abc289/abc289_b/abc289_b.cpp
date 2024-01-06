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
//97~122

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> re(n+1);
    repp(i, m){
        int a;
        cin >> a;
        re[a] = true;
    }
    vector<int> b;
    repp(i, n+1) if(!re[i]) b.push_back(i);

    vector<int> ans(n);
    repp(i, n) ans[i] = i+1;
    repp(i ,b.size()-1){
        reverse(ans.begin()+b[i], ans.begin()+b[i+1]);
    }
    repp(i, n) cout << ans[i] << " ";
    cout << endl;
}
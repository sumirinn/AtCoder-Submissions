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
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    repp(i, n) cin >> s[i];

    bool ans = false;
    sort(s.begin(), s.end());
    do{
        int cnt = 0;
        repp(i, n-1){
            int c = 0;
            repp(j, m) if(s[i][j]!=s[i+1][j]) c++;
            if(c==1) cnt++;
        }
        if(cnt==n-1) ans = true;
    }while(next_permutation(s.begin(), s.end()));
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
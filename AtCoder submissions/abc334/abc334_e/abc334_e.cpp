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
using mint = modint998244353;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    repp(i, h) cin >> s[i];

    vector<vector<int>> id(h, vector<int>(w));
    int n = 0;
    repp(i, h)repp(j, w)if(s[i][j]=='#'){
        id[i][j] = n++;
    }

    dsu uf(n); 
    int base = n;
    repp(i, h)repp(j, w)if(s[i][j]=='#'){
        repp(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
            if(s[ni][nj]!='#') continue;
            int a = id[i][j], b = id[ni][nj];
            if(uf.same(a, b)) continue;
            base--;
            uf.merge(a, b);
        }
    }

    mint sum = 0;
    int cnt = 0;
    repp(i, h)repp(j, w)if(s[i][j]!='#'){
        cnt++;
        int now = base;
        now++;
        set<int> st;
        repp(v, 4){
            int ni = i + di[v], nj = j + dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
            if(s[ni][nj]!='#') continue;
            st.insert(uf.leader(id[ni][nj]));
        }
        now -= st.size();
        sum += now;
    }

    mint ans = sum / cnt;
    cout << ans.val() << endl;
}
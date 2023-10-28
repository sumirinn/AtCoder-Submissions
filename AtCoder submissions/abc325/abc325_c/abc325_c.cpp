#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int h, w;
char s[1009][1009];

int main(){
    cin >> h >> w;
    rep(i, h)rep(j, w) cin >> s[i][j];

    int ans = 0;
    int n = h * w;
    dsu uf(n);
    rep(i, h)rep(j, w){
        if(s[i][j]!='#') continue;
        ans++;
        for(int di=-1; di<=1; di++){
            for(int dj=-1; dj<=1; dj++){
                int ni = i+di, nj = j+dj;
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(s[ni][nj]!='#') continue;
                if(i==ni && j==nj) continue;
                int v = i*w + j, u = ni*w + nj;
                if(uf.same(v, u)) continue;
                uf.merge(v, u);
                ans--;
            }
        }
    }

    cout << ans << endl;
}
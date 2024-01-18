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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

ll dp[16][2][130][130];

int main(){
    ll n;
    cin >> n;
    n++;

    vector<int> digit;
    while(n){
        digit.push_back(n%10);
        n /= 10;
    }
    reverse(digit.begin(), digit.end());
    int m = digit.size();

    ll ans = 0;
    for(int k=1; k<=126; k++){
        repp(i, m+1)repp(j, 2)repp(s, k+1)repp(r, k) dp[i][j][s][r] = 0;
        dp[0][0][0][0] = 1;
        repp(i, m)repp(j, 2)repp(s, k+1)repp(r, k){
            repp(d, 10){
                int ni = i + 1;
                int nj = j;
                int ns = s + d;
                int nr = (r*10+d) % k;
                if(ns > k) continue;
                if(j==0){
                    if(digit[i] < d) continue;
                    if(digit[i] > d) nj = 1;
                }

                dp[ni][nj][ns][nr] += dp[i][j][s][r];
            }
        }
        ans += dp[m][1][k][0];
    }
    
    cout << ans << endl;
}

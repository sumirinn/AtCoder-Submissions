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
    int t; cin >> t;
    rep(ti, t){
        ll n; cin >> n;

        ll p, q;
        for(int i= 2; i*i*i<=n; i++){
            if(n%i!=0) continue;
            if((n/i)%i==0){
                p = i;
                q = n/(p*p);
            }else{
                q = i;
                p = round(sqrt(n/q));
            }
            break;
        }
        cout << p << " " << q << endl;
    }
}
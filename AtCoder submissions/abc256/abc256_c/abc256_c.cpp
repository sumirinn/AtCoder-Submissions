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
using MP = map<int, vector<int>>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);} // change max
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c2(ll n) {return n*(n-1) / 2;}
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    int h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    int ans = 0;
    for(int i11=1; i11<=h1; i11++){
        for(int i21=1; i21<=h1; i21++){
            int i31 = h1 - i11 - i21;
            if(i31<=0) continue;
            for(int i12=1; i12<=h2; i12++){
                for(int i22=1; i22<=h2; i22++){
                    int i32 = h2 - i12 - i22;
                    if(i32<=0) continue;
                    for(int i13=1; i13<=h3; i13++){
                        for(int i23=1; i23<=h3; i23++){
                            int i33= h3 - i13 - i23;
                            if(i33<=0) continue;
                            if(i11+i12+i13==w1&&i21+i22+i23==w2&&i31+i32+i33==w3) ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
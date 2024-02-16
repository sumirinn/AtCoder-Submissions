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
using P = pair<int, ll>;
using mint = modint998244353;
void chmax(ll& x, ll y) {x = max(x, y);}
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int inf = 1001001001;
const ll INF = 1e18;
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
int gcd(int a,int  b) {if(a%b==0)return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}
//97~122(a~z),65~90(A~Z)

int main(){
    string s;
    cin >> s;
    
    string t = "atcoder";
    map<string, int> mp;
    mp[s] = 0;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        string v = q.front(); q.pop();
        if(v==t){
            cout << mp[v] << endl;
            return 0;
        }
        rep(i, 6){
            string u = v;
            swap(u[i], u[i+1]);
            if(mp.find(u)==mp.end()){
                q.push(u);
                mp[u] = mp[v] + 1; 
            }
        }
    }
}
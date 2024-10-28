#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, n) for (int i = 1; i <= (n); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using ll = long long; using db = double; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<db, db>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 1e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
//using P = pair<db, int>;
using C = complex<db>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(int& x, int y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(){
    string s;
    cin >> s;
    int n = s.size();

    int d = 0;
    vector<bool> rev(n);
    rep(i,n){
        if(s[i]=='(') d++;
        if(s[i]==')') d--;
        if(d%2==1) rev[i] = true;
    }

    vector<int> rl(n);
    map<int,int> mp;
    rep(i,n){
        if(s[i]=='('){
            d++;
            mp[d] = i;
        }
        if(s[i]==')'){
            rl[i] = mp[d];
            d--;
        }
    }

    vector<int> lr(n);
    for(int i=n-1; i>=0; i--){
        if(s[i]==')'){
            d++;
            mp[d] = i;
        }
        if(s[i]=='('){
            lr[i] = mp[d];
            d--;
        }
    }

    string ans = "";
    auto change =[&](char c){
        if(97<=c) return c - 'a' + 'A';
        else return c - 'A' + 'a';
    };
    auto f =[&](auto f, int l, int r, int type)->void{
        if(type==0){
            for(int i=l; i<=r; i++){
                if(s[i]=='('){
                    f(f,i+1,lr[i]-1,1);
                    i = lr[i];
                }
                else{
                    if(rev[i]) ans += change(s[i]);
                    else ans += s[i];
                }
            }
        }
        if(type==1){
            for(int i=r; i>=l; i--){
                if(s[i]==')'){
                    f(f,rl[i]+1,i-1,0);
                    i = rl[i];
                }
                else{
                    if(rev[i]) ans += change(s[i]);
                    else ans += s[i];
                }
            }
        }
    };
    f(f,0,n-1,0);

    cout << ans << endl;
}
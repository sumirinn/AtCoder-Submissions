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
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; 
using pli = pair<ll, int>; using pil = pair<int, ll>;
const int inf = 1001001001; 
const ll INF = 3e18;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m);で定義できる
//a,bが0だと使えないことに注意
ll gcd(ll a, ll b) {if(a%b==0)return b; else return gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*b / gcd(a, b);}
ll c2(ll n) {return n*(n-1) / 2;} 
ll c3(ll n) {return n*(n-1)*(n-2) / 6;}
using P = pair<int, pii>;
using C = complex<double>;
void chmax(ll& x, ll y) {x = max(x, y);} 
void chmin(ll& x, ll y) {x = min(x, y);}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


bool isPalindrome(const string& s){
    if(s.find("0")!=string::npos) return false;
    string rs = s;
    reverse(rs.begin(),rs.end());
    return s==rs;
}


int main(){
    ll n;
    cin >> n;

    vector<pll> ps;
    for(ll i=2; i*i<=n; i++){
        if(n%i) continue;
        string s = to_string(i);
        reverse(s.begin(),s.end());
        ll j = stoll(s);
        if(n%j) continue;
        if(s.find("0")!=string::npos) continue;
        if(i<=j) ps.eb(i,j); 
    }

    set<ll> visited;
    auto f =[&](auto f, ll n)->string{
        if(visited.count(n)) return "-1";
        visited.insert(n);
        if(isPalindrome(to_string(n))) return to_string(n);

        for(auto [x,y] : ps){
            ll xy = x*y;
            if(n%xy) continue;
            string s = f(f,n/xy);
            if(s=="-1") continue;
            return to_string(x) + "*" + s + "*" + to_string(y);
        }

        return "-1";
    };

    cout << f(f,n) << endl;
}
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
//97~122(a~z)

int main(){
    int n;
    string R, C;
    cin >> n>> R >> C;

    auto f = [&](auto f, char x, vector<string> s) -> bool {
        if(x=='D'){
            string r, c;
            repp(i, n)repp(j, n){
                if(s[i][j]!='.'){
                    r += s[i][j];
                    break;
                }
            }
            repp(j, n)repp(i, n){
                if(s[i][j]!='.'){
                    c += s[i][j];
                    break;
                }
            }
            if(r==R && c==C){
                cout << "Yes" << endl;
                repp(i,n) cout << s[i] << endl;
                return true;
            }
            return false;
        }
        vector<int> p(n);
        repp(i, n) p[i] = i;
        do{
            auto t = s;
            bool ok = true;
            repp(i, n){
                if(t[i][p[i]]!='.') ok = false;
                t[i][p[i]] = x;
            }
            if(!ok) continue;
            if(f(f, x+1, t)) return true;
        } while(next_permutation(p.begin(), p.end()));
        return false;
    };

    vector<string> s(n, string(n, '.'));
    if(!f(f, 'A', s)) cout << "No" << endl;
}
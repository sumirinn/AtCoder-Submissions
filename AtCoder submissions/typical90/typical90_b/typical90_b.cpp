#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;

int main(){
    cin >> n;

    auto isvalid = [&](string t) -> bool {
        int score = 0;
        for(auto c: t){
            if(c=='(') score++;
            else score--;
            if(score<0) return false;
        }
        if(score==0) return true;
        else return false;
    };

    repp(bit, (1<<n)){
        string s = "";

        for(int i=n-1; i>=0; i--){
            if(bit & (1 << i)) s += ')';
            else s += '(';
        }

        if(isvalid(s)) cout << s << endl;
    }
}

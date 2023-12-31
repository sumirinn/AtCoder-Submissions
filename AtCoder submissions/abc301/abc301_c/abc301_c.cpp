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

//97~122
string s, t;

int main(){
    cin >> s >> t;

    int cnts[100], cntt[100];
    repp(i, 50) cnts[i] = 0; 
    repp(i, 50) cntt[i] = 0;
    repp(i, s.size()){
        if(s[i]=='@') cnts[0]++;
        else cnts[int(s[i])-96]++;
    }
    repp(i, t.size()){
        if(t[i]=='@') cntt[0]++;
        else cntt[int(t[i])-96]++;
    }

    bool ans = true;
    rep(i, 26){
        if(i==int('a')-96 || i==int('t')-96 || i==int('c')-96 || i==int('o')-96 || i==int('d')-96 || i==int('e')-96 || i==int('r')-96 ){
            if(cnts[i]<cntt[i]) cnts[0] -= (cntt[i] - cnts[i]);
            if(cnts[i]>cntt[i]) cntt[0] -= (cnts[i] - cntt[i]);
        }else{
            if(cnts[i]!=cntt[i]) ans = false;
        }
    }

    if(cnts[0]<0 || cntt[0]<0) ans =false;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

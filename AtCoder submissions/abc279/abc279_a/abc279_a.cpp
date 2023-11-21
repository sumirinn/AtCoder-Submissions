#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

string s;

int main(){
    cin >> s;

    int cnt = 0;
    repp(i, s.size()){
        if(s[i]=='v') cnt++;
        if(s[i]=='w') cnt = cnt + 2;
    }

    cout << cnt << endl;
}
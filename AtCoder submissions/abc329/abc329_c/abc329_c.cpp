#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)

int n;
char s[200009];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];

    vector<string> v;
    string c = "";
    s[n+1] = 'A';
    rep(i, n){
        c += s[i];
        if(s[i]!=s[i+1]){
            v.push_back(c);
            c = "";
        }
    }

    int abc[30];
    rep(i, 26) abc[i] = 0;
    repp(i, v.size()){
        int c = int(v[i][0]) - 96;
        int ookisa = v[i].size();
        abc[c] = max(abc[c], ookisa);
    }

    int cnt = 0;

    rep(i, 26) cnt += abc[i];
    cout << cnt << endl;
}
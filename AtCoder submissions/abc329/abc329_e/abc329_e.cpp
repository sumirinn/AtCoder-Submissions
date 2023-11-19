#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
string s, t;

int main(){
    cin >> n >> m >> s >> t;

    vector<bool> used(n);
    queue<int> q;
    auto in = [&](int c){
        if(c<0 || n<c+m || used[c]) return;
        repp(i, m) if(s[c+i]!='#' && s[c+i]!=t[i]) return;
        used[c] = true;
        q.push(c);
    };

    repp(i, n-m+1) in(i);

    while(!q.empty()){
        int i = q.front();
        q.pop();
        repp(j, m) s[i+j] = '#';
        for(int k=i-m+1; k<=i+m-1; k++) in(k);
    }

    if(s == string(n, '#')) cout << "Yes" << endl;
    else cout << "No" << endl;
}
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

    bool used[200009];
    repp(i, n) used[i] = false;

    queue<int> q;
    auto in = [&](int c){
        if(n<c+m) return;
        repp(i, m) if(s[c+i]!='#' && s[c+i]!=t[i]) return;
        used[c] = true;
        q.push(c);
    };

    repp(i, n-m+1) in(i);

    while(!q.empty()){
        int i = q.front();
        q.pop();
        repp(j, m) s[i+j] = '#';
        for(int k=i-m+1; k<=i+m-1; k++) if(!(used[k]) && 0<=k && k<n) in(k);
    }

    if(s == string(n, '#')) cout << "Yes" << endl;
    else cout << "No" << endl;
}
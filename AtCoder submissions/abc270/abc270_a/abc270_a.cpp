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

int main(){
    int a, b;
    cin >> a >> b;
    bool t[10];
    rep(i, 3) t[i] = false;
    if(a%2 + b%2>=1) t[1] = true;
    if((a/2)%2 + (b/2)%2>=1) t[2] = true;
    if((a/4)%2 + (b/4)%2>=1) t[3] = true;
    int c = 1;
    int s = 0;
    rep(i, 3){
        if(t[i]) s += c;
        c *= 2;
    }
    cout << s << endl;

}
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

char s1, s2, t1, t2;

int main(){
    cin >> s1 >> s2 >> t1 >> t2;

    int s, t;
    if(s1=='A'){
        if(s2=='B' || s2=='E') s=1;
        if(s2=='C' || s2=='D') s=2;
    }
    if(s1=='B'){
        if(s2=='A' || s2=='C') s=1;
        if(s2=='E' || s2=='D') s=2;
    }
    if(s1=='C'){
        if(s2=='B' || s2=='D') s=1;
        if(s2=='A' || s2=='E') s=2;
    }
    if(s1=='D'){
        if(s2=='C' || s2=='E') s=1;
        if(s2=='A' || s2=='B') s=2;
    }
    if(s1=='E'){
        if(s2=='A' || s2=='D') s=1;
        if(s2=='C' || s2=='B') s=2;
    }

    t = s;
    s1 = t1;
    s2 = t2;
    if(s1=='A'){
        if(s2=='B' || s2=='E') s=1;
        if(s2=='C' || s2=='D') s=2;
    }
    if(s1=='B'){
        if(s2=='A' || s2=='C') s=1;
        if(s2=='E' || s2=='D') s=2;
    }
    if(s1=='C'){
        if(s2=='B' || s2=='D') s=1;
        if(s2=='A' || s2=='E') s=2;
    }
    if(s1=='D'){
        if(s2=='C' || s2=='E') s=1;
        if(s2=='A' || s2=='B') s=2;
    }
    if(s1=='E'){
        if(s2=='A' || s2=='D') s=1;
        if(s2=='C' || s2=='B') s=2;
    }

    if(s==t) cout << "Yes" << endl;
    else cout << "No" << endl;
}
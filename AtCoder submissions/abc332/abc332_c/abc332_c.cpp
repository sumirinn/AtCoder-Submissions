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

int n, m;
char s[1009];

int main(){
    cin >> n >> m;
    rep(i, n) cin >> s[i];

    int cntmt = m;
    int a = 0;
    int cntat = 0;

    rep(i, n){
        if(s[i]=='0'){
            m = cntmt;
            a = cntat;
        }
        if(s[i]=='1'){
            if(m<1){
                if(a<1) cntat++;
                else a--;
            }else{
                m--;
            }
        }
        if(s[i]=='2'){
            if(a<1) cntat++;
            else a--;
        }
    }

    cout << cntat << endl;
}
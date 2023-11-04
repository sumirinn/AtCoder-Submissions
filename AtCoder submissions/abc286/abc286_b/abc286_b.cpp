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

int n;
char s[1009];
bool nya[1009];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];

    rep(i, n-1){
        if(s[i]=='n' && s[i+1]=='a') nya[i] = true;
    }
    rep(i, n){
        cout << s[i];
        if(nya[i]) cout << "y";
    }
    cout << endl;
}
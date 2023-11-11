#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

char s[300009];
int n, q;

int main(){
    cin >> n >> q;
    rep(i, n) cin >> s[i];

    int mozi[300009];
    rep(i, 300005) mozi[i] = 0; 

    rep(i, n-1) if(s[i]==s[i+1]) mozi[i]++;

    int m[300009];
    m[0] = 0;
    rep(i, n) m[i] = mozi[i] + m[i-1];

    rep(d, q){
        int l, r;
        cin >> l >> r;
        cout << m[r-1] - m[l-1] << endl;
    }
    
}

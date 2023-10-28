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

int main(){
    cin >> n;

    int ans = 0;
    for(int i=n; i<=919; i++){
        int s = i / 100;
        int t = (i/10) % 10;
        int u = i % 10;
        if(s*t==u){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}
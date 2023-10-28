#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

long long n, w[1009], x[1009];

int main(){
    cin >> n;
    rep(i, n) cin >> w[i] >> x[i];

    long long answer = 0;
    rep(i, 24){
        long long ans = 0;
        rep(j, n){
            if((i+x[j])%24>=9 && (i+x[j])%24<=17){
                ans += w[j];
            }
        }
        answer = max(ans, answer);
    }

    cout << answer << endl;
}
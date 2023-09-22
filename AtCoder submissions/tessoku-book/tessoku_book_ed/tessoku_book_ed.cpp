#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int dp[32][300009];

int main(){
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        string s = to_string(i);
        dp[0][i] = i;
        for(int j=0; j<s.size(); j++){
            int a = s[j] - '0';
            dp[0][i] -= a;
        }
    }

    for(int d=1; d<=29; d++){
        for(int i=1; i<=n; i++) dp[d][i] = dp[d-1][dp[d-1][i]];
    }

    for(int i=1; i<=n; i++){
        int c = i;
        for(int d=29; d>=0; d--){
            if((k/(1<<d))%2!=0) c = dp[d][c];
        }

        cout << c << endl;
    }

}
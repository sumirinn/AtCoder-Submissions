#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n;
int h[100009], dp[100009];
vector<int> ans;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> h[i];

    dp[1] = 0;
    if(h[1]>h[2]) dp[2] = h[1] - h[2];
    else dp[2] = h[2] - h[1];

    for(int i=3; i<=n; i++){
        int dp1, dp2;

        if(h[i]>h[i-1]) dp1 = h[i] - h[i-1];
        else dp1 = h[i-1] - h[i];

        if(h[i]>h[i-2]) dp2 = h[i] - h[i-2];
        else dp2 = h[i-2] - h[i];

        dp[i] = min(dp[i-1]+dp1, dp[i-2]+dp2);
    }

    int p = n;

    while(true){
        ans.push_back(p);
        if(p==1) break;

        if(dp[p-1]+abs(h[p]-h[p-1])==dp[p]) p = p - 1;
        else p = p - 2;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(int i=0; i<ans.size(); i++){
        if(i!=0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
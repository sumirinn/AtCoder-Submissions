#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, s;
int a[69];
bool dp[69][10009];
vector<int> ans;

int main(){
    cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> a[i];

    dp[0][0] = true;
    for(int i=1; i<=s; i++) dp[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=s; j++){
            if(j<a[i]) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i-1][j]==true || dp[i-1][j-a[i]]==true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if(dp[n][s]==false){
        cout << -1 << endl;
        return 0;
    }

    int p = s;
    for(int i=n; i>=1; i--){
        if(dp[i-1][p]==false){
            p -= a[i];
            ans.push_back(i);
        }
    }

    reverse(ans.begin(),ans.end());

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        if(i) cout << " ";
        cout << ans[i];
    }
}
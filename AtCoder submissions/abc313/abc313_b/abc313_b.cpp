#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, m, a[2509], b[2509];

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> a[i] >> b[i];
    
    int ans[59];
    for(int i=1; i<=n; i++) ans[i] = 0;
    for(int i=1; i<=m; i++) ans[b[i]]++;
    
    int cnt=0, answer=0;
    for(int i=1; i<=n; i++){
        if(ans[i]==0){
            cnt++;
            answer = i;
        }
    }
    
    
    if(cnt==1) cout << answer << endl;
    else cout << -1 << endl;
}
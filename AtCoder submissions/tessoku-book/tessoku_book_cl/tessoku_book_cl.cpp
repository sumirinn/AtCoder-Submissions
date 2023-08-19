#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k;
int a[100009], b[100009], r[100009];

int main(){
  //入力
  cin >> n >> k;
  for(int i=1; i<=n; i++) cin >> a[i];
  
  // 累積和
  b[0] = 0;
  for(int i=1; i<=n; i++) b[i] = b[i-1] +a[i];
  
  //しゃくとり法
  for(int i=1; i<=n; i++){
    if(i==1) r[i] = 0;
    else r[i] = r[i-1];
    
    while(r[i]<n && b[r[i]+1]-b[i-1]<=k) r[i] += 1;
    
  }
  
  //出力
  long long ans = 0;
  for(int i=1; i<=n; i++) ans += (r[i] - i + 1);
  cout << ans << endl;
}
  
 
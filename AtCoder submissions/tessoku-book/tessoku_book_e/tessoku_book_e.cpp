#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n, k, ans = 0;
  cin >> n >> k;
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int a = k - i - j;
      if(1<=a && a<=n) ans += 1;
    }
  }
  
  cout << ans << endl;
}
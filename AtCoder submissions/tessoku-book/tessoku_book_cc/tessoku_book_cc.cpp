#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n, ans=0;
  cin >> n;
  
  for(int i=0; i<8; i++){
    
    int a = 1, m=0;
    
    for(int j=0; j<i; j++) a = a * 10;
    
    m = n / a;
    m = m % 10;
    
    if(m==1) ans += (1 << i);
  }
  
  cout << ans << endl;
}
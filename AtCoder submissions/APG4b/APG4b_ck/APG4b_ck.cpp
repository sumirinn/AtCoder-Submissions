#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  int n;
  n = S.size();
  
  int ans = 1;
  
  for(int i=0; i<n; i ++){
    if(S.at(i)=='+'){
      ans++;
    }
    
    if(S.at(i)=='-'){
      ans--;
    }
  }
  
  cout << ans << endl;
}

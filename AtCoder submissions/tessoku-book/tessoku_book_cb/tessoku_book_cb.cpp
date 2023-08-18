#include <bits/stdc++.h>
using namespace std;

int n;
int A[109];
bool ans = false;

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];
  
  for(int i=1; i<=n-2; i++){
    for(int j=i+1; j<=n-1; j++){
      for(int k=j+1; k<=n; k++){
        if(A[i]+A[j]+A[k]==1000) ans =true;
      }
    }
  }
  
  if(ans==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
        

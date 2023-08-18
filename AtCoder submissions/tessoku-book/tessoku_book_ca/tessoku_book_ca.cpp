#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  bool ans = false;
  for(int i=a; i<b+1; i++){
    if(100%i==0)ans = true;
  }
  if(ans==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
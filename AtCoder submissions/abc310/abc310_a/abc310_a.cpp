#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  
  int m = 1000000;
  
  for(int i=0; i<n; i++){
    int a = 0;
    cin >> a;
    m = min(m, a);
  }
  
  int c = q + m;
  
  if(c<p){
    cout << c << endl;
  }else{
    cout << p << endl;
  }
}
  
  
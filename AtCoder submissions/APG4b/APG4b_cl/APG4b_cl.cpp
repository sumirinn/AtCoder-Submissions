#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
 
  for(int i=0; i<N; i++){
    string p;
    int x;
    cin >> p >> x;
    
    if(p=="+"){
      A += x;
    }
    
    if(p=="-"){
      A -= x;
    }
    
    if(p=="*"){
      A *= x;
    }
    
    if(p=="/"){
      
      if(x==0){
        cout << "error" << endl;
        break;
      }
      
      A /= x;
    }
    
    cout << i + 1 << ":" << A << endl;
  }
}
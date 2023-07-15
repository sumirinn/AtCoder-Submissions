#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> v(N);
  int a = 0;
  
  for(int i=0; i<N; i++){
    cin >> v[i];
    a = a + v[i];
  }
  
  int b = 0;
  b = a / N;
  
  for(int j=0; j<N; j++){
    if(v[j]<b){
      cout << b - v[j] << endl;
    }
    else{
      cout << v[j] - b << endl;
    }
  }
}
 
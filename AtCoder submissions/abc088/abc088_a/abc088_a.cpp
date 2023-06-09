#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a;
  
  b = n % 500;
  
  if(b<=a){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

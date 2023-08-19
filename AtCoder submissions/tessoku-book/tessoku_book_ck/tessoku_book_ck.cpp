#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

double f(double x){
  return x*x*x + x;
}

int main(){
  int n;
  cin >> n;
  
  double left = 0, right = 100, mid;
  for(int i=0; i<=20; i++){
    mid = (left + right) / 2.0;
    double val = f(mid);
    
    if(val>1.0*n) right =mid;
    else left = mid;
  }
  
  cout << mid << endl;
}
  
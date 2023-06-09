#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,d,e,f;
  cin >> a;
  
  b = a % 100;
  c = a / 100;
  d = b % 10;
  e = b / 10;
  cout << c + d + e << endl;
  
}
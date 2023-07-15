#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int m = min(A, min(B, C));
  int M = max(A, max(B, C));
  
  cout << M - m << endl;
}
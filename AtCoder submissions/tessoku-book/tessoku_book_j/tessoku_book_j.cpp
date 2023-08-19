#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, a[100009];
int d, l[100009], r[100009];
int L[100009], R[100009];

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i];
  cin >> d;
  for(int i=1; i<=d; i++) cin >> l[i] >> r[i];
  
  for(int i=0; i<=n+1; i++){
    L[i] = 0;
    R[i] = 0;
  }
  
  for(int i=1; i<=n; i++) L[i] = max(L[i-1], a[i]);
  for(int i=n; i>=1; i--) R[i] = max(R[i+1], a[i]);
  
  for(int i=1; i<=d; i++) cout << max(L[l[i]-1], R[r[i]+1]) << endl;
}
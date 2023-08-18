#include <bits/stdc++.h>
using namespace std;

int n, A[100009], S[100009];
int q, L[100009], R[100009];

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];
  cin >> q;
  for(int i=1; i<=q; i++) cin >> L[i] >> R[i];
  
  S[0] = 0;
  for(int i=1; i<=n; i++) S[i] = S[i-1] + A[i];
  
  for(int i=1; i<=q; i++){
    int m = S[R[i]] - S[L[i]-1];
    int l = (R[i] - L[i] + 1) - m;
    
    if(m>l) cout << "win" << endl;
    if(m==l) cout << "draw" << endl;
    if(m<l) cout << "lose" << endl;
  }
}
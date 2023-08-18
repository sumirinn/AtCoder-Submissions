#include <bits/stdc++.h>
using namespace std;

int n, X[100009], Y[100009];
int Z[1509][1509], ANS[1509][1509];
int q, A[100009], B[100009], C[100009], D[100009];

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> X[i] >> Y[i];
  cin >> q;
  for(int i=1; i<=q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  
  for(int i=0; i<=1500; i++){
    for(int j=0; j<=1500; j++){
      Z[i][j] = 0;
      ANS[i][j] = 0;
    }
  }
  
  for(int i=1; i<=n; i++) Z[X[i]][Y[i]] += 1;
  
  for(int i=1; i<=1500; i++){
    for(int j=1; j<=1500; j++) ANS[i][j] = ANS[i][j-1] + Z[i][j];
  }
  
  for(int i=1; i<=1500; i++){
    for(int j=1; j<=1500; j++) ANS[i][j] = ANS[i-1][j] + ANS[i][j];
  }
  
  for(int i=1; i<=q; i++){
    cout << ANS[C[i]][D[i]] + ANS[A[i]-1][B[i]-1] -ANS[A[i]-1][D[i]] - ANS[C[i]][B[i]-1] << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int n, a[100009], b[100009], c[100009], d[100009];
int x[1509][1509], y[1509][1509];
int ans;

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  
  for(int i=0; i<=1500; i++){
    for(int j=0; j<=1500; j++){
      x[i][j] = 0;
      y[i][j] = 0;
    }
  }
  
  for(int i=1; i<=n; i++){
    x[a[i]][b[i]] += 1;
    x[c[i]][d[i]] += 1;
    x[c[i]][b[i]] -= 1;
    x[a[i]][d[i]] -= 1;
  }
  
  for(int i=0; i<=1500; i++){
    y[i][0] = x[i][0];
    for(int j=1; j<=1500; j++) y[i][j] = y[i][j-1] + x[i][j];
  }
  
  for(int i=1; i<=1500; i++){
    for(int j=0; j<=1500; j++) y[i][j] = y[i][j] + y[i-1][j];
  }
  
  ans = 0;
  for(int i=0; i<=1500; i++){
    for(int j=0; j<=1500; j++){
      if(y[i][j]>=1) ans += 1;
    }
  }
  
  cout << ans << endl;
}
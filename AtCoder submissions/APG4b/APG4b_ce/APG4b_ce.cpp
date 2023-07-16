#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }
 
  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  
  vector<vector<char>> v(N, vector<char>(N));
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      v[i][j] = '-';
    }
  }
  
  for(int k=0; k<M; k++){
    v[A[k]-1][B[k]-1] = 'o';
    v[B[k]-1][A[k]-1] = 'x';
  }
  
  for(int l=0; l<N; l++){
    for(int a=0; a<N; a++){
      cout << v[l][a];
      if(a==N-1){
        cout << endl;
      }else{
        cout << ' ';
      }
    }
  }
}
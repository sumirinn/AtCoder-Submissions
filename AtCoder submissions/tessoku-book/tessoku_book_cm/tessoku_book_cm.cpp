#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

//写してるだけ
vector<long long> Enumerate(vector<long long> A){
  vector<long long> Sumlist;
  for(int i=0; i<(1<<A.size()); i++){
    long long sum = 0;
    for(int j=0; j<A.size(); j++){
      int wari = (1<<j);
      if ((i/wari)%2==1) sum += A[j];
    }
    Sumlist.push_back(sum);
  }
  return Sumlist;
}

long long N, K;
long long A[39];

int main(){
  cin >> N >> K;
  for(int i=1; i<=N; i++) cin >> A[i];
  
  vector<long long> L1, L2;
  for(int i=1; i<=N/2; i++) L1.push_back(A[i]);
  for(int i=N/2+1; i<=N; i++) L2.push_back(A[i]);
  
  vector<long long> Sum1 = Enumerate(L1);
  vector<long long> Sum2 = Enumerate(L2);
  sort(Sum1.begin(), Sum1.end());
  sort(Sum2.begin(), Sum2.end());
  
  for(int i=0; i<Sum1.size(); i++){
    int pos = lower_bound(Sum2.begin(), Sum2.end(), K-Sum1[i]) - Sum2.begin();
    if(pos<Sum2.size() && Sum2[pos]==K-Sum1[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
}

  
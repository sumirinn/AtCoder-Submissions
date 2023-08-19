#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, a[100009];
int q, x[100009];

int main(){
  cin >> n;
  for(int i=1; i<=n; i++) cin >> a[i];
  cin >> q;
  for(int i=1; i<=q; i++) cin >> x[i];
  
  sort(a+1, a+n+1);
  
  for(int i=1; i<=q; i++){
    int pos = lower_bound(a+1, a+n+1, x[i]) - a;
    cout << pos - 1 << endl;
  }
}
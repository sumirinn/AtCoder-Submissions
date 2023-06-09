#include <iostream>
using namespace std;

int N;
int A[200];         

int main() {
  int N;
  int A[200]; 
  cin >> N;
    
  for (int i = 0; i < N; ++i){
    cin >> A[i];
  }

    int res = 0;

    while (true) {
        bool e = false;  
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) e = true;  
        }

        if (e) break;  

        for (int i = 0; i < N; ++i) {
            A[i] /= 2;
        }
        ++res;  
    }

    cout << res << endl;
}
#include <iostream>
using namespace std;

int main(){
  int n,a,b;
  cin >> n;
  a = n / 5;
  b = n % 5;

  if(b>2){
    cout << a*5 + 5 << endl;
  }else{
    cout << a*5 << endl;
  }
}
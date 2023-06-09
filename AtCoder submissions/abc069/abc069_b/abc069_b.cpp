#include <iostream>
#include <string>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  
  int a,b;
  a = s.size();
  
  cout << s[0] << a - 2 << s[a-1] << endl;
}
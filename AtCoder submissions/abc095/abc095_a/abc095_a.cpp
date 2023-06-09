#include <iostream>
#include <string>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  
  int c = 0;
  if(s[0] == 'o')++c;
  if(s[1] == 'o')++c;
  if(s[2] == 'o')++c;
  
  cout << 700 + 100*c << endl;
}
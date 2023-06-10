#include <iostream>
using namespace std;

int main(){
  char p,q;
  cin >> p >> q;
  
  int a,b,c;
  
  if(p=='A'){
    a = 0;
  }else if(p=='B'){
    a = 3;
  }else if(p=='C'){
    a = 4;
  }else if(p=='D'){
    a = 8;
  }else if(p=='E'){
    a = 9;
  }else if(p=='F'){
    a = 14;
  }else if(p=='G'){
    a = 23;
  }
  
  if(q=='A'){
    b = 0;
  }else if(q=='B'){
    b = 3;
  }else if(q=='C'){
    b = 4;
  }else if(q=='D'){
    b = 8;
  }else if(q=='E'){
    b = 9;
  }else if(q=='F'){
    b = 14;
  }else if(q=='G'){
    b = 23;
  }
  
  if(a<b){
    c = b - a;
  }else{
    c = a - b;
  }
  
  cout << c << endl;
}
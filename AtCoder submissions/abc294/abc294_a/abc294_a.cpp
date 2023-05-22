#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int A;
        cin >> A;
        if(A%2==0){
           cout << A << endl;
        }
    }
}
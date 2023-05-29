#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.length();
    string N = S;

    for(int i=0; i<n/2; i++){
        N[2*i] = S[2*i+1];
        N[2*i+1] = S[2*i];
    }
    cout << N << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string w[109];

int main(){
    cin >> n;
    rep(i, n) cin >> w[i];
    
    bool ans = false;
    
    rep(i,n){
        if(w[i]=="and" || w[i]=="not" || w[i]=="that" || w[i]=="the" || w[i]=="you") ans = true;
    }
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
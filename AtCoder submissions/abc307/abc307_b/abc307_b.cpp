#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string s[109];

int main(){
    cin >> n;
    rep(i, n) cin >> s[i];
    
    bool ans = false;
    rep(i, n){
        rep(j, n){
            if(i!=j){
                string a = s[i] + s[j];
                bool ans1 = true;
                for(int k=0; k<a.size()/2; k++) if(a[k]!=a[a.size()-k-1]) ans1 = false;
            if(ans1) ans = true;
            }
        }
    }
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
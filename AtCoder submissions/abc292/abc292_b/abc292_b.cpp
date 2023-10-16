#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, q, a[109];

int main(){
    cin >> n >> q;
    
    rep(i, n) a[i] = 2;
    
    rep(i, q){
        int e = 0, s = 0;
        cin >> e >> s;
        
        if(e==1){
            a[s]--;
        }
        if(e==2){
            a[s] = a[s] - 2;
        }
        if(e==3){
            if(a[s]<=0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
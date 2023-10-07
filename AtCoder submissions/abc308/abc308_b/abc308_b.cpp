#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m, p[109];
string c[109], d[109];

int main(){
    cin >> n >> m;
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i];
    cin >> p[0];
    rep(i, m) cin >> p[i]; 
    
    int sum = 0;
    
    rep(i, n){
        int cnt = 0;
        rep(j, m){
            if(c[i]==d[j]){
                sum += p[j];
                cnt++;
            }
        }
        if(cnt==0) sum += p[0];
    }
    
    cout << sum << endl;
}
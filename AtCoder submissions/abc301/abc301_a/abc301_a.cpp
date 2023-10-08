#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n;
string s;

int main(){
    cin >> n >> s;
    
    int cntt = 0, cnta = 0;
    
    int nn = n / 2;
    if(n%2!=0) nn++;
    
    char ans;
    
    for(int i=0; i<n; i++){
        if(s[i]=='T') cntt++;
        else cnta++;
        if(cntt==nn){
            ans = 'T';
            break;
        }
        if(cnta==nn){
            ans = 'A';
            break;
        }
    }
    
    cout << ans << endl;
}
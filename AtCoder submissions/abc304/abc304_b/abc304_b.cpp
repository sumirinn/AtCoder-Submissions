#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

string n;

int main(){
    cin >> n;
    
    if(n.size()<=3) cout << n << endl;
    else{
        int cnt = 0;
        for(int i=0; i<n.size(); i++){
            if(cnt<=2){
                cout << n[i];
                cnt++;
            }
            else cout << 0;
        }
        cout << endl;
    }
}
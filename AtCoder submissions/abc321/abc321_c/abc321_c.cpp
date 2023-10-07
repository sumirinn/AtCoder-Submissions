#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int k;

int main(){
    cin >> k;
    
    vector<long long> ans;
    for(int i=2; i<(1<<10); i++){
        long long a = 0;
        for(int j=9; j>=0; j--){
            int wari = (1 << j);
            if((i/wari)%2==1){
                a *= 10;
                a += j;
            }
        }
        ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    
    cout << ans[k-1] << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, a[300009], c[100009];
vector<int> ans;

int main(){
    cin >> n;
    for(int i=1; i<=3*n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) c[i] = 0;
    
    for(int i=1; i<=3*n; i++){
        c[a[i]]++;
        if(c[a[i]]==2) ans.push_back(a[i]);
    }
    
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
}
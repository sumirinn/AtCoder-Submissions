#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int n, c[109], a[109][40], x;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        for(int j=1; j<=c[i]; j++) cin >> a[i][j];
    }
    cin >> x;
    
    vector<int> v;
    for(int i=1; i<=n; i++){
        bool kake = false;
        for(int j=1; j<=c[i]; j++) if(a[i][j]==x){
            kake = true;
        }
        if(kake) v.push_back(i);
    }
    
    if(v.size()==0){
        cout << 0 << endl;
        return 0;
    }
    
    int m = 100000;
    for(int i=0; i<v.size(); i++){
        m = min(m, c[v[i]]);
    }
    int ans = 0;
    for(int i=0; i<v.size(); i++) if(c[v[i]]==m) ans++;
    cout << ans << endl;
    for(int i=0; i<v.size(); i++) if(c[v[i]]==m) cout << v[i] << " ";
    cout << endl;
}
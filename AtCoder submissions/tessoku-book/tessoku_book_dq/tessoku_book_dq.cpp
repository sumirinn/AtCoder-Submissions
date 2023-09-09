#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, a[509][509], q, t[509];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        t[i] = i;
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    cin >> q;

    for(int i=1; i<=q; i++){
        int z, x, y;
        cin >> z >> x >> y;

        if(z==1){
            int change = t[x];
            t[x] = t[y];
            t[y] = change;
        }

        if(z==2){
            cout << a[t[x]][y] << endl;
        }
    }
}

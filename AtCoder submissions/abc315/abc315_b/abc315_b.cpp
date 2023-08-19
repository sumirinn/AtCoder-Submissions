#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int m, d[109];
int n, a, b;

int main(){
    cin >> m;
    for(int i=1; i<=m; i++) cin >> d[i];

    for(int i=1; i<=m; i++) n += d[i];

    n = n / 2;

    for(int i=1; i<=m; i++){
        n -= d[i];
        if(n<0){
            cout << i << " " << n + d[i] + 1 << endl;
            return 0;
        }
    }
}

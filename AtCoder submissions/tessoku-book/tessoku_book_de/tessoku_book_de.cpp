#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k;
int a[100009];
bool b[100009];

int main(){
    cin >> n >> k;
    for(int i=1; i<=k; i++) cin >> a[i];
    for(int i=1; i<=k; i++) b[i] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i>=a[j] && b[i-a[j]]==false) b[i] = true;
        }
    }

    if(b[n]==true) cout << "First" << endl;
    else cout << "Second" << endl;
}
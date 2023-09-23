#include <iostream>
using namespace std;

int n;
int ans[100];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=7; j++){
            int a;
            cin >> a;
            ans[i] += a;
        }
    }

    for(int i=1; i<=n; i++){
        cout << ans[i];
        if(i!=n) cout << " ";
    }

    cout << endl;
}
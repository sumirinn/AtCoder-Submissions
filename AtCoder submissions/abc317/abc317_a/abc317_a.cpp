#include <iostream>
using namespace std;

int n, h, x, ans;
int p[109];

int main(){
    cin >> n >> h >> x;
    for(int i=1; i<=n; i++) cin >> p[i];
    
    int hp = x- h;
    p[0] = -1;

    for(int i=1; i<=n; i++){
        if(p[i-1]<hp && p[i]>=hp) ans = i;
    }

    cout << ans << endl;
}
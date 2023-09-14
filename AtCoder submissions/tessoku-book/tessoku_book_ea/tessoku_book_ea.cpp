#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

int n;
long long a[100009], ans=0;
map<int, int> m;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++){
        ans += m[a[i]];
        m[a[i]]++;
    }

    cout << ans << endl;
}

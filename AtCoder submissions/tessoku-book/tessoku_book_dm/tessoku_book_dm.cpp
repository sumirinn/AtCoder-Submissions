#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, cnt[109];
long long a[200009];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++) cnt[a[i]%100] += 1;

    long long ans = 0;

    for(int i=1; i<50; i++) ans += cnt[i] * cnt[100-i];
    ans += cnt[0] * (cnt[0]-1) / 2;
    ans += cnt[50] * (cnt[50]-1) / 2;

    cout << ans << endl;
}

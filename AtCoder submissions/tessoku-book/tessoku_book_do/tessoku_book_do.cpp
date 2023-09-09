#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long n, a[100009], b[100009];

long long total(int ta,int in){
    long long sum = 0;
    for(int i=1; i<=n; i++){
        long long c1 = a[i];
        if(ta==2) c1 = - a[i];
        long long c2 = b[i];
        if(in==2) c2 = - b[i];

        if(c1+c2>=0) sum += c1 + c2;
    }

    return sum;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i];

    cout << max({total(1,1),total(1,2),total(2,1),total(2,2)})<< endl;
}


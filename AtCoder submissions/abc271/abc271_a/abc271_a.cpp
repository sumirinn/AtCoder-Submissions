#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
//97~122

int main(){
    int n;
    cin >> n;
    int a = n % 16;
    int b = n / 16;
    if(0<=b && b<=9) cout << b;
    else{
        char c = 'A' + b - 10;
        cout << c;
    }
    if(0<=a && a<=9) cout << a;
    else{
        char c = 'A' + a - 10;
        cout << c;
    }
    cout << endl;
}
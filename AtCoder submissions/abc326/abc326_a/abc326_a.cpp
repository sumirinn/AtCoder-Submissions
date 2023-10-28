#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int x, y;

int main(){
    cin >> x >> y;

    int a = y - x;
    if(a<=2 && a>=-3) cout << "Yes" << endl;
    else cout << "No" << endl;
}
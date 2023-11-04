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

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int k;

int main(){
    cin >> k;
    for(int i=0; i<k; i++) cout << s[i];
    cout << endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)

string s;

int main(){
    cin >> s;

    repp(i, s.size()){
        if(65<=int(s[i]) && int(s[i])<=90){
            cout << i + 1 << endl;
        }
    }
}
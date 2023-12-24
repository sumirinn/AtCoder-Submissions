#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define repp(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

string s;

int main(){
    cin >> s;

    int pos = -1;

    repp(i, s.size()) if(s[i]=='a') pos = i + 1;

    cout << pos << endl;
}
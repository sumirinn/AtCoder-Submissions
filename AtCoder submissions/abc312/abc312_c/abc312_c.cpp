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

int n, m;
long long a[200009], b[200009];
vector<pair<int, int>> c;

int main(){
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(i, n) c.push_back(make_pair(a[i], 0));
    rep(i, m) c.push_back(make_pair(b[i]+1, 1));
    sort(c.begin(), c.end());

    int A = 0, B = m;
    for(int i=0; i<c.size(); i++){
        if(c[i].second==0) A++;
        if(c[i].second==1) B--;
        if(A>=B){
            cout << c[i].first << endl;
            return 0;
        }
    }
}
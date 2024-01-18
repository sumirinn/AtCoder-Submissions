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
using P = pair<int, int>;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
//97~122(a~z)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    repp(i, n) cin >> p[i];

    for(int i=n-2; i>=0; i--){
        if(p[i]>p[i+1]){
            int j = n - 1;
            while(p[i]<p[j]) j--;
            swap(p[i], p[j]);
            reverse(p.begin()+i+1, p.end());
            break;
        }
    }

    repp(i, n) cout << p[i] << " ";
    cout << endl;
}
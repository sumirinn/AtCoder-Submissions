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
using P = pair<ll, ll>;
//97~122(a~z)

int main(){
    vector<int> c(9);
    repp(i, 9) cin >> c[i];

    vector<int> p(9);
    repp(i, 9) p[i] = i;

    int cnt = 0, tot = 0;
    do{
        bool ok = true;
        auto f = [&](int i, int j, int k){
            vector<pair<int,int>> d;
            d.emplace_back(p[i], c[i]);
            d.emplace_back(p[j], c[j]);
            d.emplace_back(p[k], c[k]);
            sort(d.begin(), d.end());
            if(d[0].second==d[1].second) ok = false;
        };
        f(0,1,2);
        f(3,4,5);
        f(6,7,8);
        f(0,3,6);
        f(1,4,7);
        f(2,5,8);
        f(0,4,8);
        f(2,4,6);
        if(ok) cnt++;
        tot++;
    } while(next_permutation(p.begin(), p.end()));
    double ans = 1.*cnt/tot;
    printf("%.10f\n", ans);
}
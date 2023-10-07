#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int n, m, a[109], b[109];
char s[109][109];

int main(){
    cin >> n >> m;
    rep(i, m) cin >> a[i];
    rep(i, n) rep(j, m) cin >> s[i][j];
    
    int now[109];
    rep(i, n){
        now[i] = 0;
        rep(j, m) if(s[i][j]=='o') now[i] += a[j];
        now[i] += i;
    }
    
    int M = 0;
    rep(i, n) M = max(M, now[i]);
    
    vector<vector<int>> v(100);
    
     for(int i=0; i<n; i++){
        rep(j, m){
            if(s[i+1][j]=='x') v[i].push_back(a[j]);
        }
    }
    
     for(int i=0; i<n; i++){
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    
    
    for(int i=0; i<n; i++){
        int ans = 0;
        int p = M - now[i+1];
        while(p>0){
            p -= v[i][ans];
            ans++;
        }
        cout << ans << endl;
    }
   
   
}
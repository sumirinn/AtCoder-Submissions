#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
    int n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;

    vector<int> a;
    rep(i,n){
        if(s[i]=='1'){
            a.push_back(i);
            while(i<n && s[i]=='1') i++;
        }
    }

    int cnt = 0;
    int pos = a[k];
    while(pos!=n && s[pos]=='1'){
        cnt++;
        pos++;
    }

    rep(i,n){
        if(i==a[k]) i += cnt;
        if(i>=n) break;
        cout << s[i];
        if(i==a[k-1]) rep(j,cnt) cout << '1';
    }
    cout << endl;
}
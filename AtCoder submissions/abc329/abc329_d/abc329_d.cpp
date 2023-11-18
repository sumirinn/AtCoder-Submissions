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

int n, m, a[200009];

int main(){
    cin >> n >> m;
    rep(i, m) cin >> a[i];

    int A[200009];
    rep(i, n) A[i] = 0;

    int max_num = a[1];
    int max_siz = 1;
    rep(i, m){
        A[a[i]]++;
        if(A[a[i]]<max_siz) cout << max_num << endl;
        else{
            if(max_num<=a[i] && A[a[i]]==max_siz)cout << max_num << endl;
            else{
                max_num = a[i];
                max_siz = A[a[i]];
                cout << max_num << endl;
            }
        }
    }
}
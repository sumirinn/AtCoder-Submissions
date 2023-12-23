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

int h, m;

int main(){
    cin >> h >> m;

    int a = h / 10, b = h % 10, c = m / 10, d = m % 10;

    while(true){
        h = a*10 + c;
        m = b*10 + d;

        if(h<=23 && m<=59){
            cout << a << b << " " << c << d << endl;
            return 0;
        }

        d++;

        if(d==10){
            d = 0;
            c++;
        }

        if(c==6){
            c = 0;
            b++;
        }

        if(b==10){
            b = 0;
            a++;
        }

        if(a*10+b==24){
            a = 0;
            b = 0;
        }
    }
}
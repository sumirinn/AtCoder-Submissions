#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int h, k, w;
char c[19][109], d[19][109];
int ans = 0;


int main(){
    cin >> h >> w >> k;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> c[i][j];
        }
    }

    for(int i=0; i<(1<<h); i++){
        int count = 0;
        int K = k;

        for(int s=1; s<=h; s++){
            for(int t=1; t<=w; t++) d[s][t] =c[s][t];
        }

        for(int j=1; j<=h; j++){
            int wari = (1<<(j-1));
            if((i/wari)%2==0) continue;
            K -= 1;
            for(int a=1; a<=w; a++) d[j][a] = '#';
        }

        vector<pair<int, int>> v;

        if(K>=0){

        for(int s=1; s<=w; s++){
            int count2 = 0;
            for(int t=1; t<=h; t++){
                if(d[t][s]=='.') count2++;
            }
            v.push_back(make_pair(count2, s));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        for(int s=0; s<K; s++){
            int num = v[s].second;
            for(int t=1; t<=h; t++) d[t][num] = '#';
        }

        for(int s=1; s<=h; s++){
            for(int t=1; t<=w; t++){
                if(d[s][t]=='#') count++;
            }
        }

        ans = max(ans, count);
    }
    }

    cout << ans << endl;
}
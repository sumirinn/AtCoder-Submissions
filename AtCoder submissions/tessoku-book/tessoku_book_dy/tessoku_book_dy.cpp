#include <iostream>
#include <algorithm>
#include <queue>
#include<string>
using namespace std;

int n, x, pos;
char ans[200009];
queue<int> q;

int main(){
    cin >> n >> x;
    for(int i=1; i<=n;  i++) cin >> ans[i];

    q.push(x);
    ans[x] = '@';

    while(q.empty()==false){
        pos = q.front();
        q.pop();
        if(ans[pos-1]=='.' && pos-1>=1){
            ans[pos-1] = '@';
            q.push(pos-1);
        }

        if(ans[pos+1]=='.' && pos+1<=n){
            ans[pos+1] = '@';
            q.push(pos+1);
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i];
    cout << endl;
}

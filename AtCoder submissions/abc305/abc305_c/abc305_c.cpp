#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int h, w;
char s[509][509];
int k[509], l[509];

int main(){
    cin >> h >> w;
    for(int i= 1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> s[i][j];
        }
    }
    
    for(int i=1; i<=h; i++) k[i] = 0;
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j]=='#') k[i]++;
        }
    }
    
    int a = 0;
    
    for(int i=1; i<=h-1; i++){
        if(k[i]==k[i+1]+1 && k[i+1]!=0) a = i+1;
        if(k[i]+1==k[i+1] && k[i]!=0) a = i;
    }
    
    for(int i=1; i<=w; i++) l[i] = 0;
    
    for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
            if(s[j][i]=='#') l[i]++;
        }
    }
    
    int b = 0;
    
    for(int i=1; i<=w-1; i++){
        if(l[i]==l[i+1]+1 && l[i+1]!=0) b = i+1;
        if(l[i]+1==l[i+1] && l[i]!=0) b = i;
    }
    
    cout << a << " " << b << endl;
}
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind{
    public:
    int par[100009];
    int siz[100009];

    void init(int N){
        for(int i=1; i<=N; i++) par[i] = -1;
        for(int i=1; i<=N; i++) siz[i] = 1;
    }

    int root(int x){
        while(true){
            if(par[x]==-1) break;
            x = par[x];
        }
        return x;
    }

    void unite(int u, int v){
        int RootU = root(u);
        int RootV = root(v);
        if(RootU==RootV) return;
        if(siz[RootU]<siz[RootV]){
            par[RootU] = RootV;
            siz[RootV] = siz[RootU] + siz[RootV];        
        }
        else{
            par[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
        }
    }

    bool same(int u, int v){
        if(root(u)==root(v)) return true;
        return false;
    }
};

int n, m, a[100009], b[100009];
int q, qt[100009], x[100009], u[100009], v[100009];
string ans[100009];

UnionFind uf;
bool c[100009];

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> a[i] >> b[i];
    cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> qt[i];
        if(qt[i]==1) cin >> x[i];
        if(qt[i]==2) cin >> u[i] >> v[i];
    }

    for(int i=1; i<=m; i++) c[i] = false;
    for(int i=1; i<=q; i++) if(qt[i]==1) c[x[i]] = true;

    uf.init(n);
    for(int i=1; i<=m; i++){
        if(c[i]==false && uf.same(a[i], b[i])==false){
            uf.unite(a[i], b[i]);
        }
    }

    for(int i=q; i>=1; i--){
        if(qt[i]==1){
            if(uf.same(a[x[i]], b[x[i]])==false) uf.unite(a[x[i]], b[x[i]]);
        }
        if(qt[i]==2){
            if(uf.same(u[i], v[i])==true) ans[i] = "Yes";
            else ans[i] = "No";
        }
    }

    for(int i=1; i<=q; i++) if(qt[i]==2) cout << ans[i] << endl;
}
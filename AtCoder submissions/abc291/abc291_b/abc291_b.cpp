#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

vector<long long> original_sort(vector<long long> A){

    int N = A.size();

    //長さNの列Aが与えられるので、Aをソートする
    //-------------------------------------------
    for(int j=0; j<N; j++){
        for(int i=0; i<N-1; i++ ){
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
            }
        }
    }

    //-------------------------------------------

    return A;
}

int main(){
    
    long long N;
    cin >> N;
    vector<long long> X(5*N);
    for(int i=0;i<5*N;i++){
        cin >> X[i];
    }

    X = original_sort(X);

    long long sum = 0;
    for(int i=N;i<4*N;i++){
        sum += X[i];
    }

    long double answer = sum;
    answer /= 3*N;
    cout << setprecision(10) << answer << endl;

}
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'007;

int count_matching_pairs(int N, const vector<vector<int>>& a) {
    vector<long long> dp(1 << N, 0);
    dp[0] = 1; // 初期状態

    for (int mask = 0; mask < (1 << N); ++mask) {
        int i = __builtin_popcount(mask); // 現在ペアにしている男性の数
        for (int j = 0; j < N; ++j) {
            if ((mask & (1 << j)) == 0 && a[i][j] == 1) {
                dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % MOD;
            }
        }
    }

    return dp[(1 << N) - 1];
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    cout << count_matching_pairs(N, a) << endl;
    return 0;
}

// atcoder Educational DP Contest   N - Slimes
// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
using namespace std;

template<class T> void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int64_t> s(N+1, 0);
    for (int i = 0; i < N; i++) s[i+1] = s[i] + a[i];

    vector<vector<int64_t>> dp(N, vector<int64_t>(N, INT64_MAX));
    for (int i = 0; i < N; i++) dp[i][i] = 0LL;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            for (int k = i; k < j; k++) {
                chmin(dp[i][j], dp[i][k] + dp[k+1][j] + s[j+1] - s[i]);
            }
        }
    }

    cout << dp[0][N-1] << endl;
}

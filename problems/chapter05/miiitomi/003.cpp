// AtCoder Typical DP Contest   A - コンテスト
// https://atcoder.jp/contests/tdpc/tasks/tdpc_contest

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> p.at(i);

    int W = 10000;

    vector<vector<bool>> dp(N, vector<bool>(W+1, false));  // N × (W+1)

    dp[0][0] = true;
    dp[0][p[0]] = true;

    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w - p[i] >= 0) dp[i][w] = (dp[i-1][w] || dp[i-1][w-p[i]]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    int ans = 0;
    for (int w = 0; w <= W; w++) {
        if (dp[N-1][w]) ans++;
    }

    cout << ans << endl;
}

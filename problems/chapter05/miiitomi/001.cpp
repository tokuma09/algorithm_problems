// Atcoder Educational DP Contest  C - Vacation
// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> dp(N, vector<int>(3));  // dp は N×3 の二重配列

    // dp[i][j] は i 日目に J をするケースでのi日目までの最大幸福量（j=0,1,2 -> J=A,B,C) とする
    // 初日は a[0], b[0], c[0] そのまま.
    dp[0][0] = a.at(0);
    dp[0][1] = b.at(0);
    dp[0][2] = c.at(0);

    // dp[i][j] の更新
    for (int i = 1; i < N; i++) {
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][2], dp[i-1][0]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    // dp[N-1] の最大値を出力
    cout << *max_element(dp[N-1].begin(), dp[N-1].end()) << endl;
}

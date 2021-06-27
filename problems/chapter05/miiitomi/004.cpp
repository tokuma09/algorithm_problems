#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力
    // 1行目: N W k
    // 2行目: a_0 a_1 ... a_{N-1}
    int N, W, k;
    cin >> N >> W >> k;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    vector<vector<int>> dp(N, vector<int>(W+1, 1e9));  // N × W+1 で十分大きい数を入れる

    // dp[i][w] には i 番目までの数を用いて和を w にできるなら, その時使う数の個数の最小値とする
    dp[0][0] = 0;
    if (a[0] <= W) dp[0][a[0]] = 1;

    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w - a[i] >= 0) {
                dp[i][w] = min(dp[i-1][w], dp[i-1][w-a[i]] + 1);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    if (dp[N-1][W] <= k) cout << "Yes" << endl;
    else cout << "No" << endl;
}

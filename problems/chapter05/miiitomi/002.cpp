#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    vector<vector<bool>> dp(N, vector<bool>(W+1, false));  // N × (W+1)

    // dp[i][w] は, i (= 0, ..., N-1) 番目までの数を使って w にすることができるか否か
    dp[0][0] = true;
    if (a[0] <= W) dp[0][a[0]] = true;

    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w - a[i] >= 0) dp[i][w] = (dp[i-1][w] || dp[i-1][w-a[i]]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    if (dp[N-1][W]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

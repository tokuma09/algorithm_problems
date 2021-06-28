#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    vector<vector<bool>> dp(N, vector<bool>(W+1, false));  // N×(W+1)の二重配列.

    // dp[i][w] は i 番目までの数を(いくつでも)使って w にできるか否か.
    // dp[0] をまず埋める.
    for (int w = 0; w <= W; w += a.at(0)) dp.at(0).at(w) = true;

    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w - a[i] < 0) dp[i][w] = dp[i-1][w];
            else dp[i][w] = (dp[i-1][w] || dp[i-1][w-a[i]] || dp[i][w-a[i]]);
        }
    }

    if (dp[N-1][W]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

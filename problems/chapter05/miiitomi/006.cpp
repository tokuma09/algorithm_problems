#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1行目: N W
    // 2行目: a_0 a_1 ... a_{N-1}
    // 3行目: m_0 m_1 ... m_{N-1}
    int N, W;
    cin >> N >> W;
    vector<int> a(N), m(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> m[i];

    vector<vector<bool>> dp(N, vector<bool>(W+1, false));

    for (int x = 0; x <= m[0]; x++) {
        if (x * a[0] > W) break;
        else dp[0][x*a[0]] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int w = 0; w <= W; w++) {
            if (not dp[i][w]) continue;
            for (int x = 0; x <= m[i+1]; x++) {
                if (w + (x * a[i+1]) > W) break;
                else dp[i+1][w + (x * a[i+1])] = true;
            }
        }
    }

    if (dp[N-1][W]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

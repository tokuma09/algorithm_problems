// 立命館大学プログラミングコンテスト2018 Day1  D - 水槽
// https://onlinejudge.u-aizu.ac.jp/beta/room.html#RitsCamp18Day1/problems/D
// 注：解けてない

#include <bits/stdc++.h>
using namespace std;

double f(int i, int j, vector<int> &s) {
    return (s[j+1] - s[i] + 0.0) / (j - i + 1.0);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> s(N+1, 0);
    for (int i = 0; i < N; i++) s[i+1] = s[i] + a[i];

    vector<vector<double> > dp(M, vector<double>(N, 0.0));
    for (int i = 0; i < N; i++) dp[0][i] = f(0, i, s);

    for (int m = 0; m < M-1; m++) {
        for (int i = 0; i < N; i++) {
            dp[m+1][i] = max(dp[m+1][i], dp[m][i]);
            for (int j = i + 1; j < N; j++) {
                dp[m+1][j] = max(dp[m+1][j], dp[m][i] + f(i+1, j, s));
            }
        }
    }

    cout << fixed << setprecision(10) << dp[M-1][N-1] << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int s_size = s.size();
    int t_size = t.size();

    vector<vector<int>> dp(s_size+1, vector<int>(t_size+1, 0));

    // dp[i][j] は s[0:i-1] と t[0:j-1] の最大部分文字列の長さとする
    for (int i = 0; i < s_size; i++) {
        for (int j = 0; j < t_size; j++) {
            if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    string ans = "";
    int i = s_size - 1;
    int j = t_size - 1;

    // dp から最大部分文字列を復元する
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            ans = s[i] + ans;
            i--;
            j--;
        } else if (dp[i+1][j] > dp[i][j+1]) {
            j--;
        } else {
            i--;
        }
    }

    cout << ans << endl;
}

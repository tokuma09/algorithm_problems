// https://atcoder.jp/contests/dp/tasks/dp_p

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(vector<vector<int>> &G, vector<pair<ll, ll>> &dp, int v, int from) {
    for (int w : G[v]) {
        if (w == from) continue;
        dfs(G, dp, w, v);
        dp[v].first = (dp[v].first * ((dp[w].first + dp[w].second) % MOD)) % MOD;
        dp[v].second = dp[v].second * dp[w].first % MOD;
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // 0 をルートとした木としてみる.
    // dp[i].first / dp[i].second は i=白/黒のときの i 以下の部分木の塗り分け方.
    vector<pair<ll, ll>> dp(N, make_pair(1, 1));
    dfs(G, dp, 0, -1);
    cout << (dp[0].first + dp[0].second) % MOD << endl;
}

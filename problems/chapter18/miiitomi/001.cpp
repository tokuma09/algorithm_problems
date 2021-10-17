// https://yukicoder.me/problems/no/763
// https://drken1215.hatenablog.com/entry/2021/08/06/104900

#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> &G, vector<bool> &used, int v, int p) {
    bool used_child = false;
    for (int w : G[v]) {
        if (w == p) continue;
        rec(G, used, w, v);
        if (used[w]) used_child = true;
    }
    if (!used_child) used[v] = true;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> used(N, false);
    rec(G, used, 0, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) ans += used[i];
    cout << ans << endl;
}

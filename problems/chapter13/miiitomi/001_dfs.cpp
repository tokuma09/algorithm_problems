#include <iostream>
#include <vector>
using namespace std;

vector<bool> seen;

void dfs(const vector<vector<int>> &G, int i) {
    if (seen[i]) return;

    seen[i] = true;
    for (int v : G[i]) {
        dfs(G, v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            dfs(G, i);
            ans++;
        }
    }

    cout << ans << endl;
}

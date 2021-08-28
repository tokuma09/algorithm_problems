#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

    vector<bool> seen(N, false);
    int ans = 0;
    queue<int> Q;

    for (int i = 0; i < N; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        Q.push(i);
        ans++;

        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int v : G[x]) {
                if (!seen[v]) {
                    seen[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    cout << ans << endl;
}

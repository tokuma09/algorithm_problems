// AtCoder ABC132   E - Hopscotch Addict
// https://atcoder.jp/contests/abc132/tasks/abc132_e

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(3*N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v + N);
        G[u + N].push_back(v + 2*N);
        G[u + 2*N].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;

    vector<int> dist(3*N, -1);
    dist[S] = 0;
    queue<int> Q;
    Q.push(S);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int w : G[v]) {
            if (dist[w] != -1) {
                continue;
            } else if (w == T) {
                dist[w] = dist[v] + 1;
                break;
            } else {
                dist[w] = dist[v] + 1;
                Q.push(w);
            }
        }

        if (dist[T] != -1) break;
    }

    if (dist[T] == -1) cout << -1 << endl;
    else cout << dist[T] / 3 << endl;
}

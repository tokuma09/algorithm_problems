#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> seen(N, false);
    queue<int> Q;
    Q.push(s);
    seen[s] = true;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (seen[w]) continue;
            seen[w] = true;
            Q.push(w);
        }
    }

    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

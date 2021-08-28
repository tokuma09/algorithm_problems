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

    vector<int> color(N, -1);
    queue<int> Q;

    for (int i = 0; i < N; i++) {
        if (color[i] != -1) continue;

        color[i] = 0;
        Q.push(i);

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int w : G[v]) {
                if (color[w] == -1) {
                    color[w] = 1 - color[v];
                    Q.push(w);
                } else if (color[w] == color[v]) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
}

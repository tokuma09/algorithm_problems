#include <bits/stdc++.h>
using namespace std;

int rec(vector<vector<int>> &G, vector<int> &path, int v) {
    if (path[v] != -1) return path[v];

    int longest_path = -1;
    for (int nv : G[v]) {
        longest_path = max(longest_path, rec(G, path, nv));
    }
    path[v] = longest_path + 1;
    return path[v];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }

    vector<int> path(N, -1);
    for (int v = 0; v < N; v++) rec(G, path, v);

    cout << *max_element(path.begin(), path.end()) << endl;
}

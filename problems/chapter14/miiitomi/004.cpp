#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30);

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> c;
    int s, g;
    for (int h = 0; h < H; h++) {
        string S;
        cin >> S;
        for (int w = 0; w < W; w++) {
            if (S[w] == 's') s = h * W + w;
            if (S[w] == 'g') g = h * W + w;
        }
        c.push_back(S);
    }

    int N = H * W;
    vector<vector<pair<int, int>>> G(N);
    for (int x = 0; x < N; x++) {
        if (x % W < W-1) {
            int nx = x+1;
            if (c[nx/W][nx%W] == '#') G[x].push_back(make_pair(nx, 1));
            else G[x].push_back(make_pair(nx, 0));
        }
        if (x % W > 0) {
            int nx = x - 1;
            if (c[nx/W][nx%W] == '#') G[x].push_back(make_pair(nx, 1));
            else G[x].push_back(make_pair(nx, 0));
        }
        if (x / W < H-1) {
            int nx = x + W;
            if (c[nx/W][nx%W] == '#') G[x].push_back(make_pair(nx, 1));
            else G[x].push_back(make_pair(nx, 0));
        }
        if (x / W > 0) {
            int nx = x - W;
            if (c[nx/W][nx%W] == '#') G[x].push_back(make_pair(nx, 1));
            else G[x].push_back(make_pair(nx, 0));
        }
    }

    vector<int> dist(N, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>>> que;
    que.push(make_pair(dist[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        int d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push(make_pair(dist[e.first], e.first));
            }
        }
    }

    if (dist[g] <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);

int main() {
    int K;
    cin >> K;
    vector<vector<pair<int, int>>> G(K);
    for (int i = 0; i < K; i++) {
        G[i].push_back(make_pair((i+1)%K, 1));
        G[i].push_back(make_pair((10*i)%K, 0));
    }

    vector<int> dist(K, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>>> que;
    que.push(make_pair(dist[1], 1));

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

    cout << dist[0] + 1 << endl;
}

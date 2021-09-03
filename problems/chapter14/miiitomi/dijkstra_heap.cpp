#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N);
    for (int i = 0; i < N; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<ll> dist(N, INF);
    dist[s] = 0;

    priority_queue<pair<ll, int>,
                  vector<pair<ll, int>>,
                  greater<pair<ll, int>>> que;
    que.push(make_pair(dist[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (int v = 0; v < N; v++) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}

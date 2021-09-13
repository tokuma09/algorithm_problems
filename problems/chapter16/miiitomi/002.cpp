// https://onlinejudge.u-aizu.ac.jp/problems/2872

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 60);

struct Edge {
    int rev, to, dis, cost;
    Edge(int r, int t, int d, int c) {
        rev = r;
        to = t;
        dis = d;
        cost = c;
    }
};

void WarshallFloyd(vector<vector<Edge>> &G, vector<vector<vector<ll>>> &dp) {
    int N = (int)G.size();
    dp.assign(N+1, vector<vector<ll>>(N, vector<ll>(N, INF)));
    for (int i = 0; i < N; i++) {
        dp[0][i][i] = 0;
        for (auto e : G[i]) {
            dp[0][i][e.to] = e.dis;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j][i-1] + dp[i-1][i-1][k]);
            }
        }
    }
}

int rec(vector<vector<Edge>> &H, vector<bool> &seen, int v, int c, int t) {
    if (seen[v]) return 0;
    seen[v] = true;
    if (v == t) return c;

    for (auto &e : H[v]) {
        if (e.cost == 0) continue;

        int x = rec(H, seen, e.to, min(c, e.cost), t);
        if (x > 0) {
            e.cost -= x;
            H[e.to][e.rev].cost += x;
            return x;
        }
    }
    return 0;
}

int FordFulkerson(vector<vector<Edge>> &H, int s, int t) {
    int ans = 0;
    while (true) {
        vector<bool> seen((int)H.size(), false);
        int x = rec(H, seen, s, 100, t);
        ans += x;
        if (x == 0) break;
    }
    return ans;
}

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    s--;
    t--;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        u--;
        v--;
        G[u].push_back(Edge(0, v, d, c));
    }

    vector<vector<vector<ll>>> dp;
    WarshallFloyd(G, dp);

    vector<vector<Edge>> H(N);
    for (int i = 0; i < N; i++) {
        for (auto e : G[i]) {
            if (dp[N][s][t] == dp[N][s][i] + e.dis + dp[N][e.to][t]) {
                H[i].push_back(Edge((int)H[e.to].size(), e.to, e.dis, e.cost));
                H[e.to].push_back(Edge((int)H[i].size()-1, i, e.dis, 0));
            }
        }
    }

    cout << FordFulkerson(H, s, t) << endl;
}

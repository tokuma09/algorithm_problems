// https://atcoder.jp/contests/abc010/tasks/abc010_4

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int rev, to, cap;
    Edge(int r, int t, int c) {
        rev = r;
        to = t;
        cap = c;
    }
};

bool rec(vector<vector<Edge>> &G, vector<bool> &seen, int v) {
    if (seen[v]) return false;
    seen[v] = true;
    if (v == (int)G.size()-1) return true;

    for (auto &e : G[v]) {
        if (e.cap == 0) continue;
        if (rec(G, seen, e.to)) {
            G[e.to][e.rev].cap++;
            e.cap--;
            return true;
        }
    }
    return false;
}

int FordFulkerson(vector<vector<Edge>> &G) {
    int ans = 0;
    while (true) {
        vector<bool> seen((int)G.size(), false);
        if (rec(G, seen, 0)) ans++;
        else break;
    }
    return ans;
}

int main() {
    int N, g, e;
    cin >> N >> g >> e;
    N++;

    vector<vector<Edge>> G(N);
    for (int i = 0; i < g; i++) {
        int p;
        cin >> p;
        G[p].push_back(Edge((int)G[N-1].size(), N-1, 1));
        G[N-1].push_back(Edge((int)G[p].size()-1, p, 1));
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(Edge((int)G[b].size(), b, 1));
        G[b].push_back(Edge((int)G[a].size()-1, a, 1));
    }

    cout << FordFulkerson(G) << endl;
}

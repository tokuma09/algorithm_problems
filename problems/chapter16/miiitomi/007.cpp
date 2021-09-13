// https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day1/problems/H

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

struct Edge {
    int rev, to, cap;
    Edge(int r, int t, int c) : rev(r), to(t), cap(c) {}
};

int rec(vector<vector<Edge>> &G, vector<bool> &seen, int v, int t, int f) {
    if (seen[v]) return 0;
    seen[v] = true;
    if (v == t) return f;

    for (auto &e : G[v]) {
        if (e.cap == 0) continue;
        int flow = rec(G, seen, e.to, t, min(f, e.cap));
        if (flow == 0) continue;
        e.cap -= flow;
        G[e.to][e.rev].cap += flow;
        return flow;
    }
    return 0;
}

int FordFulkerson(vector<vector<Edge>> &G, int s, int t) {
    int ans = 0;
    while (true) {
        vector<bool> seen((int)G.size(), false);
        int flow = rec(G, seen, s, t, INF);
        if (flow == 0) return ans;
        else ans += flow;
    }
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<pair<int, int>> V;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == '#') V.push_back(make_pair(i, j));
        }
    }

    int s = (int)V.size();
    int t = (int)V.size() + 1;

    int num_edges = 0;

    vector<vector<Edge>> G((int)V.size()+2);
    for (int i = 0; i < (int)V.size(); i++) {
        pair<int, int> n = V[i];
        int j;

        pair<int, int> n_shita = make_pair(n.first+1, n.second);
        auto iter_shita = lower_bound(V.begin(), V.end(), n_shita);
        if (iter_shita->first == n_shita.first && iter_shita->second == n_shita.second) {
            num_edges++;
            j = distance(V.begin(), iter_shita);
            int nv = (int)G.size();
            G.push_back((vector<Edge>){});
            G[i].push_back(Edge((int)G[nv].size(), nv, INF));
            G[nv].push_back(Edge((int)G[i].size()-1, i, 0));
            G[j].push_back(Edge((int)G[nv].size(), nv, INF));
            G[nv].push_back(Edge((int)G[j].size()-1, j, 0));
            G[nv].push_back(Edge((int)G[t].size(), t, 1));
            G[t].push_back(Edge((int)G[nv].size()-1, nv, 0));
        }

        pair<int, int> n_migi = make_pair(n.first, n.second+1);
        auto iter_migi = lower_bound(V.begin(), V.end(), n_migi);
        if (iter_migi->first == n_migi.first && iter_migi->second == n_migi.second) {
            num_edges++;
            j = distance(V.begin(), iter_migi);
            int nv = (int)G.size();
            G.push_back((vector<Edge>){});
            G[nv].push_back(Edge((int)G[i].size(), i, INF));
            G[i].push_back(Edge((int)G[nv].size()-1, nv, 0));
            G[nv].push_back(Edge((int)G[j].size(), j, INF));
            G[j].push_back(Edge((int)G[nv].size()-1, nv, 0));
            G[s].push_back(Edge((int)G[nv].size(), nv, 1));
            G[nv].push_back(Edge((int)G[s].size()-1, s, 0));
        }
    }

    int ff = FordFulkerson(G, s, t);
    cout << (int)V.size() - num_edges + ff << endl;
    return 0;
}

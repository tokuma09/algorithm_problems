// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_f

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge {
    int rev, to, cap;
    bool reg;
    Edge(int r, int t, int c, bool reg_) {
        rev = r;
        to = t;
        cap = c;
        reg = reg_;
    }
};

bool rec(vector<vector<Edge>> &G, vector<bool> &seen, int v, int t) {
    if (seen[v]) return false;
    seen[v] = true;
    if (v == t) return true;

    for (auto &e : G[v]) {
        if (e.cap == 0) continue;
        if (rec(G, seen, e.to, t)) {
            e.cap--;
            G[e.to][e.rev].cap++;
            return true;
        }
    }
    return false;
}

int FordFulkerson(vector<vector<Edge>> &G, int s, int t) {
    int ans = 0;
    vector<bool> seen;
    while (true) {
        seen.assign((int)G.size(), false);
        if (rec(G, seen, s, t)) ans++;
        else break;
    }
    return ans;
}

void dfs1(vector<vector<Edge>> &G, int v, set<int> &X) {
    if (X.count(v)) return;
    X.insert(v);

    for (auto e : G[v]) {
        if (e.cap == 0) continue;
        dfs1(G, e.to, X);
    }
}

void dfs2(vector<vector<Edge>> &G, int v, set<int> &Y) {
    if (Y.count(v)) return;
    Y.insert(v);

    for (auto e : G[v]) {
        if (e.cap > 0) continue;
        dfs2(G, e.to, Y);
    }
}

int main() {
    vector<pair<int, int>> V;
    while (true) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;
        if (N == 0 && M == 0 && S == 0 && T == 0) break;
        S--;
        T--;

        vector<vector<Edge>> G(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            G[a].push_back(Edge((int)G[b].size(), b, 1, true));
            G[b].push_back(Edge((int)G[a].size()-1, a, 0, false));
        }

        int current = FordFulkerson(G, S, T);
        set<int> X, Y;
        dfs1(G, S, X);
        dfs2(G, T, Y);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!Y.count(i)) continue;

            for (auto e : G[i]) {
                if (e.cap == 0 || !e.reg) continue;
                if (X.count(e.to)) ans++;
            }
        }
        if (ans == 0) V.push_back(make_pair(current, 0));
        else V.push_back(make_pair(current+1, ans));
    }

    for (int i = 0; i < (int)V.size(); i++) {
        cout << V[i].first << " " << V[i].second << endl;
    }
}

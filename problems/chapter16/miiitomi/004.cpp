// https://onlinejudge.u-aizu.ac.jp/problems/1163

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int rev, to, cap;
    Edge(int r, int t, int c) {
        rev = r;
        to = t;
        cap = c;
    }
};

int gcd(int m, int n) {
    if (m < n) swap(m, n);
    if (n == 0) return m;
    return gcd(n, m % n);
}

bool rec(vector<vector<Edge>> &G, vector<bool> &seen, int v) {
    if (seen[v]) return false;
    seen[v] = true;
    if (v == (int)G.size() - 1) return true;

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
    vector<int> ans;
    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<int> b(m), r(n);
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        vector<vector<Edge>> G(m+n+2);
        for (int i = 1; i <= m; i++) {
            G[0].push_back(Edge(0, i, 1));
            G[i].push_back(Edge(i, 0, 0));
        }
        for (int i = m + 1; i <= m + n; i++) {
            G[i].push_back(Edge(i-m-1, m+n+1, 1));
            G[m+n+1].push_back(Edge(0, i, 0));
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gcd(b[i], r[j]) == 1) continue;
                int x = i + 1;
                int y = j + m + 1;
                G[x].push_back(Edge((int)G[y].size(), y, 1));
                G[y].push_back(Edge((int)G[x].size()-1, x, 0));
            }
        }

        ans.push_back(FordFulkerson(G));
    }

    for (int x : ans) cout << x << endl;
}

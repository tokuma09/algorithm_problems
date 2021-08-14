// AtCoder ARC090   D - People on a Line
// https://atcoder.jp/contests/arc090/tasks/arc090_b

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

void dfs(vector<vector<pair<int, int>>> &G, vector<bool> &reached, vector<int> &x, bool &b, int i) {
    reached[i] = true;
    for (pair<int, int> p : G[i]) {
        if (reached[p.first]) {
            if (x[i] + p.second != x[p.first]) {
                b = true;
                return;
            }
        } else {
            x[p.first] = x[i] + p.second;
            dfs(G, reached, x, b, p.first);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<vector<pair<int, int>>> G(N, vector<pair<int, int>>(0));

    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        G[l].push_back(make_pair(r, d));
        G[r].push_back(make_pair(l, -d));
        uf.unite(l, r);
    }

    set<int> root;
    for (int i = 0; i < N; i++) {
        root.insert(uf.root(i));
    }

    vector<bool> reached(N, false);
    vector<int> x(N);
    bool b = false;

    for (int r : root) {
        x[r] = 0;
        dfs(G, reached, x, b, r);
    }

    if (b) cout << "No" << endl;
    else cout << "Yes" << endl;
}

// https://atcoder.jp/contests/jag2012autumn/tasks/icpc2012autumn_c

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

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        vector<pair<int, pair<int, int>>> V(m);
        for (int i = 0; i < m; i++) {
            int s, t, c;
            cin >> s >> t >> c;
            s--;
            t--;
            V[i].first = c;
            V[i].second = make_pair(s, t);
        }
        sort(V.begin(), V.end());

        UnionFind uf(n);

        vector<int> E;
        for (int i = 0; i < m; i++) {
            if (uf.issame(V[i].second.first, V[i].second.second)) continue;
            E.push_back(V[i].first);
            uf.unite(V[i].second.first, V[i].second.second);
        }

        cout << E[n/2 - 1] << endl;
    }
}

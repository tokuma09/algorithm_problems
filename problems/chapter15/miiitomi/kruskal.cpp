// https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_f?lang=ja

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
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> V(M);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        V[i].first = c;
        V[i].second = make_pair(u, v);
    }
    sort(V.begin(), V.end());

    UnionFind uf(N);

    long long ans = 0LL;
    for (int i = 0; i < M; i++) {
        if (uf.issame(V[i].second.first, V[i].second.second)) continue;
        ans += V[i].first;
        uf.unite(V[i].second.first, V[i].second.second);
    }

    cout << ans << endl;
}

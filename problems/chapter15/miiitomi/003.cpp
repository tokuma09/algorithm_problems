// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1350

#include <iostream>
#include <vector>
#include <algorithm>
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
        u--;
        v--;
        V[i].first = c;
        V[i].second = make_pair(u, v);
    }
    sort(V.begin(), V.end());

    UnionFind uf(N);

    long long minimum_cost = 0LL;
    vector<pair<int, pair<int, int>>> W;
    for (int i = 0; i < M; i++) {
        if (uf.issame(V[i].second.first, V[i].second.second)) continue;
    
        minimum_cost += V[i].first;
        W.push_back(V[i]);
        uf.unite(V[i].second.first, V[i].second.second);
    }

    long long sum_cost = 0LL;
    int counter = 0;
    for (auto e : W) {
        UnionFind uf2(N);
        long long cost = 0LL;
        for (int i = 0; i < M; i++) {
            if (V[i] == e || uf2.issame(V[i].second.first, V[i].second.second)) continue;
            cost += V[i].first;
            uf2.unite(V[i].second.first, V[i].second.second);
        }
        if (uf2.size(0) != N || cost > minimum_cost) {
            sum_cost += e.first;
            counter++;
        }
    }

    cout << counter << " " << sum_cost << endl;
}

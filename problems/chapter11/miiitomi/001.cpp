// AtCoder ABC075   C - Bridge
// https://atcoder.jp/contests/abc075/tasks/abc075_c

#include <iostream>
#include <vector>
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
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        UnionFind uf(N);
        for (int j = 0; j < M; j++) {
            if (j != i) uf.unite(a[j], b[j]);
        }
        ans += (uf.size(0) != N);
    }

    cout << ans << endl;
}

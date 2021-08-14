// AtCoder ABC049   D - 連結
// https://atcoder.jp/contests/abc049/tasks/arc065_b

#include <iostream>
#include <vector>
#include <map>
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
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind uf1(N);
    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        uf1.unite(p, q);
    }

    UnionFind uf2(N);
    for (int j = 0; j < L; j++) {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        uf2.unite(r, s);
    }

    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        pair<int, int> p = make_pair(uf1.root(i), uf2.root(i));
        V[i] = p;
    }
    map<pair<int, int>, int> M;
    for (int i = 0; i < N; i++) {
        if (M.count(V[i])) {
            M[V[i]] += 1;
        } else {
            M[V[i]] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (i < N-1) {
            cout << M[V[i]] << " ";
        } else {
            cout << M[V[i]] << endl;
        }
    }
}

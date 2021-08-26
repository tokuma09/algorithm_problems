// AtCoder ABC120   D - Decayed Bridges
// https://atcoder.jp/contests/abc120/tasks/abc120_d

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
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<int64_t> ans(M);
    ans[M-1] = ((int64_t)N * (N - 1)) / 2LL;

    UnionFind uf(N);

    for (int j = M - 1; j > 0; j--) {
        ans[j-1] = ans[j];
        int a_size = uf.size(A[j]);
        int b_size = uf.size(B[j]);
        bool united = uf.unite(A[j], B[j]);
        if (united) {
            ans[j-1] -= (int64_t)a_size * b_size;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
}

// 解説読んだ
// #include "UnionFindTree.cpp"

#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    // 経路圧縮
    // 根を求める
    int root(int x)
    {
        if (par[x] == -1)
        {
            return x; // x が根の場合は x を返す
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }

    // x と y が同じグループに属するかどうか (根が一致するかどうか)
    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }
    // x を含むグループと y を含むグループとを併合する
    bool unite(int x, int y)
    {
        // x, y をそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // すでに同じグループのときは何もしない
        if (x == y)
        {
            return false;
        }
        // union by size (y 側のサイズが小さくなるようにする)
        if (siz[x] < siz[y])
        {
            swap(x, y);
        }

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    // xを含むグループのサイズ
    int size(int x)
    {
        return siz[root(x)];
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    int ans = 0;

    // どのへんを使わないかを考える
    for (int i = 0; i < M; ++i)
    {

        UnionFind uf(N);

        // それ以外のデータで実際に結合する。
        for (int j = 0; j < M; ++j)
        {
            if (j != i)
            {
                uf.unite(a[j], b[j]);
            }
        }
        // その時のグラフが連結かどうかを確認する

        int count = 0;
        for (int j = 0; j < N; ++j)
        {
            if (j == uf.root(j))
            {
                ++count;
            }
        }
        if (1 < count)
        {
            ++ans;
        }
    }
    cout << ans << endl;
}

// https://atcoder.jp/contests/jag2012autumn/tasks/icpc2012autumn_c
// 普通似とけばいいだけ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pint = pair<int, int>;
using Edge = pair<int, pint>;

struct UnionFind
{
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x)
    {
        if (par[x] == -1)
            return x; // x が根の場合は x を返す
        else
            return par[x] = root(par[x]);
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
            return false;

        // union by size (y 側のサイズが小さくなるようにする)
        if (siz[x] < siz[y])
            swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x)
    {
        return siz[root(x)];
    }
};

int main()
{
    //入力
    int N, M;
    // 繰り返す
    while (cin >> N >> M, N)
    {
        // 辺を表す構造体
        using pint = pair<int, int>;        // 両端点
        using Edge = pair<long long, pint>; // (重み, 両端点)

        // 入力
        vector<Edge> edges(M);
        for (int i = 0; i < M; ++i)
        {
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
            --edges[i].second.first;
            --edges[i].second.second;
        }

        // 辺を重み順にソート
        sort(edges.begin(), edges.end());

        // Kruskal 法
        UnionFind uf(N);
        int num = 0;       // 辺の本数
        long long res = 0; // 答え
        for (int i = 0; i < M; ++i)
        {
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;

            // 辺 (u, v) は追加できない場合
            if (uf.issame(u, v))
            {
                continue;
            }

            // 辺 (u, v) を追加するとき
            uf.unite(u, v);
            ++num;

            // メディアンに到達
            if (num == (N + 1) / 2)
            {
                res = w;
                break;
            }
        }
        cout << res << endl;
    }
}

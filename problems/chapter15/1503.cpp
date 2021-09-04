// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1350
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
    // 入力
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[i] = Edge(w, pint(u, v));
    }

    // 各辺を重みの小さい順にソート
    sort(edges.begin(), edges.end());

    // id 番目の辺を削除した場合の最小全域木を求める関数
    // id == -1 のときは、通常の最小全域木を求める
    // res は、最小全域木をなす辺番号が格納される
    auto calc = [&](vector<int> &res, int id = -1) -> long long
    {
        long long cost = 0;
        res.clear();

        // Kruskal 法
        UnionFind uf(N);
        for (int i = 0; i < edges.size(); ++i)
        {
            if (i == id)
            {
                continue;
            }
            int u = edges[i].second.first, v = edges[i].second.second;
            if (uf.issame(u, v))
            {
                continue;
            }
            res.push_back(i);
            cost += edges[i].first;
            uf.unite(u, v);
        }

        // N-1 本に満たない場合は連結でない
        if (res.size() < N - 1)
            return (1LL << 60);
        return cost;
    };

    // もとのグラフの最小全域木を求める
    vector<int> mst;
    long long base = calc(mst);

    // 最小全域木 mst に含まれる各辺 e を 1 本ずつ除去して調べる
    vector<int> dammy;
    long long num = 0, res = 0;
    for (auto id : mst)
    {
        if (calc(dammy, id) > base)
        {
            ++num;
            res += edges[id].first;
        }
    }
    cout << num << " " << res << endl;
}

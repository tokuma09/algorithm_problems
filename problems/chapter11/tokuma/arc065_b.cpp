#include <iostream>
#include <vector>
#include <map>
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
    int N, K, L;
    cin >> N >> K >> L;

    vector<int> p(K), q(K);
    vector<int> r(L), s(L);
    // unionfindでやる
    UnionFind road(N), train(N);

    for (int i = 0; i < K; ++i)
    {
        cin >> p[i] >> q[i];
        --p[i], --q[i];
        road.unite(p[i], q[i]);
    }

    for (int i = 0; i < L; ++i)
    {
        cin >> r[i] >> s[i];
        --r[i], --s[i];
        train.unite(r[i], s[i]);
    }

    // 木でやる
    map<pair<int, int>, int> root_pair;

    for (int i = 0; i < N; ++i)
    {
        // 各島の親の部分でカウントアップ
        ++root_pair[make_pair(road.root(i), train.root(i))];
    }

    for (int i = 0; i < N; ++i)
    {
        cout << root_pair[make_pair(road.root(i), train.root(i))];
        if (i < (N - 1))
        {
            cout << " ";
        }
    }
    cout << endl;
}

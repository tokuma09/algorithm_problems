#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
    }

    UnionFind uf(N);

    // 辺を追加していくことで、逆順に出力する
    // なにもないときはすべての島との組み合わせnC2だけコスト

    long long cur = N * (N - 1) / 2;
    vector<long long> res;

    // 辺0本からMまで勧めていく
    for (int i = 0; i < M; ++i)
    {
        res.push_back(cur);

        // どの島と島を結びつけているか
        int a = A[M - (i + 1)], b = B[M - (i + 1)];

        // もしすでに連結していれば、以下の部分を無視
        if (uf.issame(a, b))
        {
            continue;
        }

        //そうでなければ、連結成分それぞれのグループがつながるので、
        // N_a, N_bの掛け算だけコストが減る
        long long sa = uf.size(a), sb = uf.size(b);
        cur -= sa * sb;

        // 結合していく
        uf.unite(a, b);
    }

    // 逆順でかいておく
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
}

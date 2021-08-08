#include <iostream>
#include <vector>

using namespace std;

// union by rankでやるタイプ
template <class Abel>
struct UnionFind
{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0)
    {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0)
    {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    // 経路圧縮. 圧縮時にdiff_weightの累積和をとることで、xの重みを計算
    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    // rootによってdiff_weightにはxの重みが含まれてる。
    Abel weight(int x)
    {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w)
    {
        // root(x) と root(y) の間をつなぐので、つなぐべき辺の重みは w ではない。
        w += weight(x);
        w -= weight(y);

        // x と y の root へ (x と y が既につながっていたら false を返すようにした)
        x = root(x);
        y = root(y);
        if (x == y)
            return false;

        // rank[x] >= rank[y] となるように x と y を swap (それに合わせて w も符号反転)
        if (rank[x] < rank[y])
            swap(x, y), w = -w;

        // y (のroot) を x (のroot) の下にくっつける
        if (rank[x] == rank[y])
            ++rank[x];
        par[y] = x;

        // x が y の親になるので、x と y の差分を diff_weight[y] に記録
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y)
    {
        return weight(y) - weight(x);
    }
};
int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind<int> uf(N);
    for (int i = 0; i < M; ++i)
    {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (uf.issame(l, r))
        {
            int diff = uf.diff(l, r);
            if (diff != d)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            uf.merge(l, r, d);
        }
    }
    cout << "Yes" << endl;
}

#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

//木の上の探索
vector<bool> used;

void dfs(const Graph &G, int v, int p = -1)
{

    // 貪欲法: 利用済みのものがあれば、終わる
    bool exist = false;

    // 自分の子ノードに向かって探索
    for (auto child : G[v])
    {
        // 親ノードを参照していればスキップ
        if (child == p)
        {
            continue;
        }
        dfs(G, child, v);

        // 子ノードが再帰探索した場合に利用されていれば、existをTrueに
        if (used[child])
        {
            exist = true;
        }
    }

    // 安定集合の定義より、子ノードor 親ノードが採用されていれば、安定集合に利用できない。
    // したがってexist=Falseのときに、自身を安定集合に入れる。
    if (!exist)
    {
        used[v] = true;
    }
}
int main()
{
    // 入力
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        // 無向グラフ
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 頂点 0 を根として探索
    used.assign(N, false);
    dfs(G, 0);

    // 数える
    int res = 0;
    for (int v = 0; v < N; ++v)
    {
        if (used[v])
        {
            ++res;
        }
    }
    cout << res << endl;
}

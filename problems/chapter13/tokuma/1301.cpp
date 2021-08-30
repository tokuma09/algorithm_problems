// 連結要素のカウント
#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v)
{
    seen[v] = true; // vを訪問したことにする

    // vから行ける各頂点next_vについて、探索
    for (auto next_v : G[v])
    {
        if (seen[next_v])
        {
            continue; // もし訪れていたらスキップ
        }

        dfs(G, next_v);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //探索
    seen.assign(N, false);

    // すべての頂点について探索
    int num = 0;
    for (int v = 0; v < N; ++v)
    {
        // 訪問済みならスキップ
        if (seen[v])
        {
            continue;
        }
        dfs(G, v);

        // もし訪問済みでないものがこの探索で存在すれば、
        // その数だけ連結出ないグラフがあることがわかる
        ++num;
    }
    cout << num << endl;
}

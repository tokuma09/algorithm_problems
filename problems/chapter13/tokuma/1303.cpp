#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Graph = vector<vector<int>>;

bool bfs(const Graph &G, int s)
{
    // Gグラフ, s　支点

    int N = (int)G.size();

    // 二部グラフの色付け
    vector<int> color(N, -1);
    queue<int> que;

    // 初期条件
    color[s] = 0; //初期頂点
    que.push(s);  // todoに入れる

    // start bfs
    while (!que.empty())
    {
        // 先頭取り出し
        int v = que.front();
        que.pop();

        // vから辿れる頂点を調べる
        for (int x : G[v])
        {
            // すでに見ている場合
            if (color[x] != -1)
            {
                // もしも現在の頂点と次の頂点の色が同じなら、2部グラフではない
                if (color[x] == color[v])
                {
                    return false;
                }
                else
                {
                    // それ以外はスキップ
                    continue;
                }
            }

            // 新しい頂点については色情報を追加してTODOリストに追加
            color[x] = 1 - color[v];
            que.push(x);
        }
    }
    return true;
}

int main()
{

    // 頂点数と辺の数, 頂点s, t
    int N, M;
    cin >> N >> M;

    // グラフ入力受取 無向グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool is_bipartite = bfs(G, 0);

    if (is_bipartite)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

/***
positive
5 5
0 1
0 3
1 2
1 4
3 4

negative
5 6
0 1
0 3
1 2
1 3
1 4
3 4

***/

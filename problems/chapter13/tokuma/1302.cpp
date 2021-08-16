// s-tパスの探索
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int>>;

vector<int> bfs(const Graph &G, int s)
{
    // Gグラフ, s　支点

    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    // 初期条件
    dist[s] = 0; //初期頂点
    que.push(s); // todoに入れる

    // start bfs
    while (!que.empty())
    {
        // 先頭取り出し
        int v = que.front();
        que.pop();

        // vから辿れる頂点を調べる
        for (int x : G[v])
        {
            // すでに見ていればスキップ
            if (dist[x] != -1)
            {
                continue;
            }
            // 新しい頂点については距離情報を追加してTODOリストに追加
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main()
{

    // 頂点数と辺の数, 頂点s, t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // グラフ入力受取 有効グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点sを始点としたbfs
    vector<int> dist = bfs(G, s);
    if (dist[t] != 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

/***
example
8 12 4 7
4 1
4 2
4 6
1 3
1 6
2 5
2 7
6 7
3 0
3 7
7 0
0 5

***/

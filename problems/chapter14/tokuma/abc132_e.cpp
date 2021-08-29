// https://drken1215.hatenablog.com/entry/2019/07/01/111500
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Graph = vector<vector<int>>;

int main()
{
    int N, M;

    int s, t;

    cin >> N >> M;

    // グラフ作成
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    cin >> s >> t;
    --s, --t;

    // 距離をカウント
    // グラフのノードを3つに拡張
    vector<vector<long long>> dist(N, vector<long long>(3, -1));
    // 初期状態
    dist[s][0] = 0;
    queue<pair<int, int>> que;

    // BFS
    que.push({s, 0});
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        // vノード, parityが複製したときの位置
        int v = cur.first;
        int parity = cur.second;

        for (auto nv : G[v])
        {
            // 0->1, 1->2 2->0の順に動く
            int np = (parity + 1) % 3;

            // 未更新のところを更新
            if (dist[nv][np] == -1)
            {
                dist[nv][np] = dist[v][parity] + 1;
                que.push({nv, np});
            }
        }
    }

    int res;
    if (dist[t][0] == -1)
    {
        res = -1;
    }
    else
    {
        res = dist[t][0] / 3;
    }

    cout << res << endl;
}

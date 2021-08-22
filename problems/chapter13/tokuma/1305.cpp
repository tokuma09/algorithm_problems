// https://qiita.com/drken/items/996d80bcae64649a6580
// 出次数とシンク

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    //頂点数と辺の数
    int N, M;
    cin >> N >> M;

    // グラフ入力
    Graph G(N);
    vector<int> deg(N, 0); // 各頂点の出次数
    // vに伸びている頂点を走査したいので、逆にする
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        ++deg[a];
    }

    // シンクたちをキューに入れる
    queue<int> que;
    for (int i = 0; i < N; ++i)
    {
        if (deg[i] == 0)
        {
            que.push(i);
        }
    }

    // 順序
    vector<int> order;
    // 探索開始
    while (!que.empty())
    {
        // キューから頂点を取り出す
        int v = que.front();
        que.pop();

        order.push_back(v);

        // vに伸びている頂点を探索
        for (auto nv : G[v])
        {
            // 辺(nv, v)の削除;
            --deg[nv];

            // シンクになれば挿入
            if (deg[nv] == 0)
            {
                que.push(nv);
            }
        }
    }

    // 答えをひっくり返す
    reverse(order.begin(), order.end());
    for (auto v : order)
        cout << v << endl;
}

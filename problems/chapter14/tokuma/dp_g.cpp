#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, vector<bool> &seen,
         vector<int> &order)
{
    seen[v] = true;
    for (auto next_v : G[v])
    {
        if (seen[next_v])
        {
            continue; // すでに訪問済みなら探索しない
        }
        dfs(G, next_v, seen, order);
    }

    // v-out を記録する
    order.push_back(v);
}

vector<int> top_sort(const Graph &G)
{
    vector<bool> seen;
    vector<int> order; // トポロジカルソート順を表す

    int N = G.size();
    seen.assign(N, false); // 未訪問
    order.clear();

    // すべての頂点について探索
    for (int v = 0; v < N; ++v)
    {
        if (seen[v])
        {
            continue; // すでに訪問済みなら探索しない
        }
        dfs(G, v, seen, order);
    }
    reverse(order.begin(), order.end()); // 逆順に

    return order;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph G(N);

    // グラフ構築
    for (int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        // インデックスに合うように変更
        --x, --y;
        G[x].push_back(y);
    }

    vector<int> order = top_sort(G);

    vector<int> dp(N, 0);
    // トポロジカルソートの順でdpを実施
    for (int i = 0; i < N; ++i)
    {
        int v = order[i];
        for (auto v_next : G[v])
        {
            dp[v_next] = max(dp[v_next], dp[v] + 1);
        }
    }

    int res;
    res = *max_element(dp.begin(), dp.end());

    cout << res << endl;
}

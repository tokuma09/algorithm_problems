#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// 入力
int N; // 頂点数
// 木上の動的計画法テーブル
vector<long long> dp1, dp2;

// MOD
const int MOD = 1000000007;

void dfs(const Graph &G, int v, int p = -1)
{
    // すべての子ノードを探索
    for (auto child : G[v])
    {
        if (child == p)
        {
            continue;
        }
        dfs(G, child, v);
    }

    // 帰りがけ時に動的計画法 backwardにやってるだけ
    for (auto child : G[v])
    {
        if (child == p)
        {
            continue;
        }

        // 組み合わせを考えるので、前のものとの掛け算をする
        // MODで割らないと数値が大きくなりすぎる
        dp1[v] = dp1[v] * (dp1[child] + dp2[child]) % MOD;
        dp2[v] = dp2[v] * dp1[child] % MOD;
    }
}

int main()
{
    // 頂点数 (木なので辺数は N - 1 で確定)
    cin >> N;

    // 重みとグラフの入力受取
    Graph G(N); // グラフ
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 初期状態
    dp1.assign(N, 1), dp2.assign(N, 1);

    //深さ優先探索
    dfs(G, 0);

    // 結果
    cout << (dp1[0] + dp2[0]) % MOD << endl;
}

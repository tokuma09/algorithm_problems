#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 無限大を表す値 (ここでは 2^60 とする)
const long long INF = 1LL << 60;

// 辺を表す型，ここでは重みを表す型を long long 型とします
struct Edge
{
    int to;      // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    else
        return false;
}

int main()
{

    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a;
        --b;
        G[a].push_back(Edge(b, -c));
    }

    // ベルマンフォード法
    bool exist_negative_cycle = false;
    vector<long long> dist(N, INF);
    dist[0] = 0;

    // すべての辺についてN回反復
    for (int iter = 0; iter <= 2 * N; ++iter)
    {
        bool update = false; // 更新が発生したかどうか

        // あるノードを固定して、次のノードに移動する
        // ここが辺に関するループの部分
        for (int v = 0; v < N; ++v)
        {
            // INFのときはvからの緩和は行わない
            if (dist[v] == INF)
            {
                continue;
            }

            // vから次のノードに対して移動
            for (auto e : G[v])
            {
                //緩和処理を行って、更新されれば、true
                if (chmin(dist[e.to], dist[v] + e.w))
                {
                    if (e.to == N - 1 && iter == 2 * N)
                    {
                        exist_negative_cycle = true;
                    }
                }
            }
        }
    }

    if (exist_negative_cycle)
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << -dist[N - 1] << endl;
    }
}

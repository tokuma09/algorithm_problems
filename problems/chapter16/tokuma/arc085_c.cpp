// https://atcoder.jp/contests/arc085/tasks/arc085_c
#include <iostream>
#include <vector>

using namespace std;

// グラフを表す構造体
struct Graph
{
    // 辺を表す構造体
    // rev: 逆辺 (to, from) が G[to] の中で何番目の要素か
    // cap: 辺 (from, to) の容量
    struct Edge
    {
        int rev, from, to;
        long long cap;
        Edge(int r, int f, int t, long long c) : rev(r), from(f), to(t), cap(c) {}
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // N: 頂点数
    Graph(int N = 0) : list(N) {}

    // グラフの頂点数取得
    size_t size()
    {
        return list.size();
    }

    // Graph インスタンスを G として，
    // G.list[v] を G[v] と書けるようにしておく
    vector<Edge> &operator[](int i)
    {
        return list[i];
    }

    // 辺 e = (u, v) の逆辺 (v, u) を取得する
    Edge &redge(const Edge &e)
    {
        return list[e.to][e.rev];
    }

    // 辺 e = (u, v) に流量 f のフローを流す
    // e = (u, v) の流量が f だけ減少する
    // このとき逆辺 (v, u) の流量を増やす
    void run_flow(Edge &e, long long f)
    {
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点 from から頂点 to へ容量 cap の辺を張る
    // このとき to から from へも容量 0 の辺を張っておく
    void addedge(int from, int to, long long cap)
    {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0LL));
    }
};

struct FordFulkerson
{
    static const long long INF = 1LL << 55; // 無限大を表す値を適切に
    vector<int> seen;

    FordFulkerson() {}

    // 残余グラフ上で s-t パスを見つける (深さ優先探索)
    // 返り値は s-t パス上の容量の最小値 (見つからなかったら 0)
    // f: s から v へ到達した過程の各辺の容量の最小値
    long long fodfs(Graph &G, int v, int t, long long f)
    {
        // 終端 t に到達したらリターン
        if (v == t)
            return f;

        // 深さ優先探索
        seen[v] = true;
        for (auto &e : G[v])
        {
            if (seen[e.to])
                continue;

            // 容量 0 の辺は実際には存在しない
            if (e.cap == 0LL)
                continue;

            // s-t パスを探す
            // 見つかったら flow はパス上の最小容量
            // 見つからなかったら f = 0
            long long flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-t パスが見つからなかったら次辺を試す
            if (flow == 0LL)
                continue;

            // 辺 e に容量 flow のフローを流す
            G.run_flow(e, flow);

            // s-t パスを見つけたらパス上最小容量を返す
            return flow;
        }

        // s-t パスが見つからなかったことを示す
        return 0LL;
    }

    // グラフ G の s-t 間の最大流量を求める
    // ただしリターン時に G は残余グラフになる
    long long solve(Graph &G, int s, int t)
    {
        long long res = 0;

        // 残余グラフに s-t パスがなくなるまで反復
        while (true)
        {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            // s-t パスが見つからなかったら終了
            if (flow == 0LL)
                return res;

            // 答えを加算
            res += flow;
        }

        // no reach
        return 0LL;
    }
};
const long long INF = 1LL << 55;
int main()
{
    int N;
    cin >> N;

    Graph G(N + 2);
    vector<long long> a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // スーパーノード
    int s = N;
    int t = N + 1;

    long long max_val = 0;

    // グラフの作成
    // 最小コストを計算する形に帰着する
    for (int i = 0; i < N; ++i)
    {
        // aの値で場合わけ
        if (0 <= a[i])
        {

            // 割る操作をしないときのコストが0
            G.addedge(s, i, 0);

            // 割る操作をするときのコストがa[i]
            G.addedge(i, t, a[i]);
            max_val += a[i];
        }
        else
        {
            // 割る操作をしないときのコストが-a[i]
            G.addedge(s, i, -a[i]);

            // 割る操作をするときのコストが0
            G.addedge(i, t, 0);
        }
    }

    //　制約条件
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // 倍数の場合にはどちらかのみ押すということができないようにする。
            if (((j + 1) % (i + 1)) == 0)
            {
                G.addedge(i, j, INF);
            }
        }
    }

    // sからtにかけて
    FordFulkerson ff;
    cout << max_val - ff.solve(G, s, t) << endl;
}
